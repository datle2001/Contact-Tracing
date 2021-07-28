#include "User.h"

User::User() {
	fullName = "not_identified";
	createCSV(fullName);
}
User::User(string fullName) {
	this->fullName = fullName;
	createCSV(fullName);
}

void User::getContactfromFile(string fileName) {
	myContactFile.open(fileName, ios_base::in);
	string line;
	while (getline(myContactFile, line)) {
		stringstream sstream(line);

		string dateStr; getline(sstream, dateStr, ',');
		Date date; date = date.StringtoDate(dateStr);

		string contactName; getline(sstream, contactName, ',');

		string timeStr; getline(sstream, timeStr, ',');
		Time contactTime; contactTime = contactTime.StringtoTime(timeStr);

		records[date].addContact(contactName, contactTime, 0);
	}
	myContactFile.close();
}
void User::getTravelfromFile(string fileName) {
	myTravelFile.open(fileName, ios_base::in);
	string line;
	while (getline(myTravelFile, line)) {
		stringstream sstream(line);

		string dateStr; getline(sstream, dateStr, ',');
		Date date; date = date.StringtoDate(dateStr);

		string travelName; getline(sstream, travelName, ',');

		string timeStr; getline(sstream, timeStr, ',');
		Time arriveTime; arriveTime = arriveTime.StringtoTime(timeStr);

		getline(sstream, timeStr, ',');
		Time departTime; departTime = departTime.StringtoTime(timeStr);

		records[date].addTravel(travelName, arriveTime, departTime,0);
	}
	myTravelFile.close();
}
void User::createCSV(string fullName) {
	myTravelFile.open(fullName + "Travel.csv", ios_base::in | ios_base::out);
	string line;
	if (getline(myTravelFile, line)) {
		myTravelFile.close();
		getTravelfromFile(fullName + "Travel.csv");
	}
	else {
		myTravelFile << "Date,Place,," << endl;
		myTravelFile.close();
	}

	myContactFile.open(fullName + "Contact.csv", ios_base::in | ios_base::out);
	if (getline(myContactFile, line)) {
		myContactFile.close();
		getContactfromFile(fullName + "Contact.csv");
	}
	else {
		myContactFile << "Date,Contact," << endl;
		myContactFile.close();
	}
}
void copyFile(string name) {
	string here = "C:/Users/datqu/OneDrive/Desktop/Tiny projects/C++/ContactTracingAppNew/ContactTracingAppNew/"+name+".csv";
	std::wstring stemp = std::wstring(here.begin(), here.end());
	LPCWSTR sw = stemp.c_str();
	string there = "C:/Users/datqu/OneDrive/Desktop/Tiny projects/C++/ContactTracingAppNew/ControlCenterApp/" + name + ".csv";
	std::wstring stempe = std::wstring(there.begin(), there.end());
	LPCWSTR swe = stempe.c_str();
	CopyFile(sw, swe, false);
}
void User::closeFile() {
	copyFile(fullName + "Contact");
	copyFile(fullName + "Travel");
	copyFile("Collection");
	myTravelFile.close();
	myContactFile.close();
}

string User::getName() const {
	return fullName;
}
void User::setName(string fullName) {
	this->fullName = fullName;
}
void User::updateInfo() {
	string fullName;
	cout << "\tYour new name: ";
	getline(cin, fullName);
	setName(fullName);
	cout << "\tUpdate name successfully!" << endl << endl;
}
map<Date, DailyMovement> User::getRecords() {
	return records;
}

void User::askDate(string mode, Date& date) {
	string input; bool done = false;
	cout << "\tType the date you want to " + mode + ":\n";
	do {
		cout << "\t\tMonth: ";
		getline(cin, input);
		done = date.checkDate(input, 'm', 0);
	} while (!done);
	int month = stoi(input);
	do {
		cout << "\t\tDay: ";
		getline(cin, input);
		done = date.checkDate(input, 'd', month);
	} while (!done);
	int day = stoi(input);
	cout << endl;
	date = Date(month, day);
}
void User::askTime(Time& time) {
	string input; bool done = false;
	cout << "\t\tEnter time in 24-hour format.\n";
	do {
		cout << "\t\tHour(24h): ";
		getline(cin, input);
		done = time.checkTime(input, 'h');
	} while (!done);
	int hour = stoi(input);
	do {
		cout << "\t\tMinute: ";
		getline(cin, input);
		done = time.checkTime(input, 'm');
	} while (!done);
	int min = stoi(input);
	cout << endl;
	time = Time(hour, min);
}
string User::askChoice(string mode) {
	string choice;
	cout << "\tWhat are you trying to " + mode + "? Type \"c\" for contact or \"t\" for travel: ";
	getline(cin, choice);
	cout << endl;
	return choice;
}
string User::askContact(string mode) {
	string contactName;
	cout << "\tEnter the person's name you want to " + mode + ": ";
	getline(cin, contactName);
	cout << endl;
	return contactName;
}
string User::askPlace(string mode) {
	string travelName;
	cout << "\tEnter the place you want to add: ";
	getline(cin, travelName);
	cout << endl;
	return travelName;
}


void User::addRecord() {
	cout << "\t*Add Record*" << endl;
	string key = "add";
	Date date;  askDate(key, date);
	string choice = askChoice(key);

	switch (choice[0]) {
	case 'c':
	case 'C':
	{
		string contactName = askContact(key);

		cout << "\tEnter the time you contacted with " << contactName << ": \n\n";
		Time contactTime; askTime(contactTime);

		bool added = records[date].addContact(contactName, contactTime,1);
		if (added) {
			addContactToFile(date, contactName, contactTime);
		}
		cout << endl;
		break;
	}
	case 't':
	case 'T':
	{
		string travelName = askPlace(key);

		Time arriveTime, departTime;
		cout << "\tEnter the time you arrived at " << travelName << ": \n\n";
		askTime(arriveTime);
		cout << "\tEnter the time you departed " << travelName << ": \n\n";
		askTime(departTime);

		bool added = records[date].addTravel(travelName, arriveTime, departTime,1);
		if (added) {
			addTravelToFile(date, travelName, arriveTime, departTime);
		}
		cout << endl;
		break;
	}
	default:
		cout << "\tWrong key!\n" << endl;
	}
}
void User::removeRecord() {
	cout << "\t*Remove Record*" << endl;
	string key = "remove";
	Date date; askDate(key, date);
	string choice = askChoice(key);

	switch (choice[0]) {
	case 'c':
	case 'C':
	{
		string contactName = askContact(key);

		cout << "\tEnter the time you contacted with " << contactName << ": \n";
		Time contactTime; askTime(contactTime);

		bool removed = records[date].removeContact(contactName, contactTime);
		if (removed) {
			removeContactfromFile();
		}
		cout << endl;
		break;
	}
	case 't':
	case 'T':
	{
		string travelName = askPlace(key);

		Time arriveTime, departTime;
		cout << "\tEnter the time you arrived at " << travelName << ": \n";
		askTime(arriveTime);
		cout << "\tEnter the time you departed " << travelName << ": \n";
		askTime(departTime);

		bool removed = records[date].removeTravel(travelName, arriveTime, departTime);
		if (removed) {
			removeTravelfromFile();
		}

		cout << endl;
		break;
	}
	default:
		cout << "\tWrong key!\n" << endl;
	}
}
void User::changeRecord() {
	cout << "\t*Change Record*" << endl;
	string key = "change";
	Date date; askDate(key, date);
	string choice = askChoice(key);

	switch (choice[0]) {
	case 'c':
	case 'C':
	{
		string oldContactName = askContact(key);
		string newContactName; Time oldContactTime, newContactTime;

		cout << "\tEnter a new name (re-enter the name if you dont want to change): ";
		getline(cin, newContactName);
		cout << endl;

		cout << "\tEnter the time you contacted with " << oldContactName << ": \n";
		askTime(oldContactTime);
		cout << "\tEnter a new contact time (re-enter the time if you dont want to change): \n";
		askTime(newContactTime);

		bool changed = records[date].changeContact(oldContactName, oldContactTime, newContactName, newContactTime);
		if (changed) {
			changeContactinFile();
		}
		cout << endl;
		break;
	}
	case 't':
	case 'T':
	{
		string oldTravelName = askPlace(key);
		string newTravelName;

		Time oldArriveTime, oldDepartTime, newArriveTime, newDepartTime;

		cout << "\tEnter the time you arrived at " << oldTravelName << ": \n";
		askTime(oldArriveTime);
		cout << "\tEnter the time you departed " << oldTravelName << ": \n";
		askTime(oldDepartTime);

		cout << "\tEnter a new place name (re-enter the name if you dont want to change): ";
		getline(cin, newTravelName);
		cout << endl;

		cout << "\tEnter the time you arrived at " << newTravelName << " (re-enter the time if you dont want to change): \n";
		askTime(newArriveTime);
		cout << "\tEnter the time you departed " << newTravelName << " (re-enter the time if you dont want to change): \n";
		askTime(newDepartTime);

		bool changed = records[date].changeTravel(oldTravelName, oldArriveTime, oldDepartTime, newTravelName, newArriveTime, newDepartTime);
		if (changed) {
			changeTravelinFile();
		}
		cout << endl;
		break;
	}
	default:
		cout << "\tWrong key!\n" << endl;
	}
}

void User::addContactToFile(const Date& date, string contactName, const Time& contactTime) {
	myContactFile.open(fullName + "Contact.csv", ios_base::app);
	myContactFile << date.DatetoString() << "," << contactName << "," << contactTime.TimetoString() << endl;
	myContactFile.close();
}
void User::removeContactfromFile() {
	remove((fullName + "Contact.csv").c_str());
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		vector<Contact> contacts = it->second.getContacts();
		for (vector<Contact>::iterator it1 = contacts.begin(); it1 != contacts.end(); ++it1) {
			addContactToFile(it->first, it1->getContactName(), it1->getContactTime());
		}
	}
}
void User::changeContactinFile() {
	remove((fullName + "Contact.csv").c_str());
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		vector<Contact> contacts = it->second.getContacts();
		for (vector<Contact>::iterator it1 = contacts.begin(); it1 != contacts.end(); ++it1) {
			addContactToFile(it->first, it1->getContactName(), it1->getContactTime());
		}
	}
}

void User::addTravelToFile(const Date& date, string travelName, const Time& arriveTime, const Time& departTime) {
	myTravelFile.open(fullName + "Travel.csv", ios_base::app);
	myTravelFile << date.DatetoString() << "," << travelName << "," << arriveTime.TimetoString() << "," << departTime.TimetoString() << endl;
	myTravelFile.close();
}
void User::removeTravelfromFile() {
	remove((fullName + "Travel.csv").c_str());
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		vector<Travel> travels = it->second.getTravels();
		for (vector<Travel>::iterator it1 = travels.begin(); it1 != travels.end(); ++it1) {
			addTravelToFile(it->first, it1->getTravelName(), it1->getArriveTime(), it1->getDepartTime());
		}
	}
}
void User::changeTravelinFile() {
	remove((fullName + "Travel.csv").c_str());
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		vector<Travel> travels = it->second.getTravels();
		for (vector<Travel>::iterator it1 = travels.begin(); it1 != travels.end(); ++it1) {
			addTravelToFile(it->first, it1->getTravelName(), it1->getArriveTime(), it1->getDepartTime());
		}
	}
}

void User::printInfo() {
	cout << "\t*Print Information" << endl;
	cout << "\tUser's fullname: " << getName() << "\n";
	cout << endl;
}
void User::printAllRecord() {
	cout << "\t*Print All Record*" << endl;
	if (records.empty()) {
		cout << "\tNo record found.\n";
	}
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		cout << "\t." << (*it).first.DatetoString() << endl;
		(*it).second.printContacts();
		(*it).second.printTravels();
		cout << endl;
	}
	cout << endl;
}
void User::printAllTravelRecord() {
	cout << "\t*Print All Travel Record*\n";
	if (records.empty()) {
		cout << "\tNo record found.\n";
	}
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		if (!(*it).second.getTravels().empty()) {
			cout << "\t." << (*it).first.DatetoString() << endl;
			(*it).second.printTravels();
			cout << endl;
		}
	}
	cout << endl;
}
void User::printAllContactRecord() {
	cout << "\t*Print All Contact Record*" << endl;
	if (records.empty()) {
		cout << "\tNo record found.\n";
	}
	for (map<Date, DailyMovement>::iterator it = records.begin(); it != records.end(); ++it) {
		if (!(*it).second.getContacts().empty()) {
			cout << "\t." << (*it).first.DatetoString() << endl;
			(*it).second.printContacts();
			cout << endl;
		}
	}
	cout << endl;
}

void User::printRecordOn() {
	cout << "\t*Print Record on any date*" << endl;
	string key = "print";
	Date date; askDate(key, date);
	if (records.find(date) == records.end()) {
		cout << "\tNo record found on " << date.DatetoString() << "\n\n";
		return;
	}
	records[date].printTravels();
	records[date].printContacts();
}
void User::printTravelRecordOn() {
	cout << "\t*Print Travel Contact Record on any date*" << endl;
	string key = "print";
	Date date; askDate(key, date);
	if (records.find(date) == records.end()) {
		cout << "\tNo travel record found on " << date.DatetoString() << "\n\n";
		return;
	}
	records[date].printTravels();
}
void User::printContactRecordOn() {
	cout << "\t*Print Contact Record on any date*" << endl;
	string key = "print";
	Date date; askDate(key, date);
	if (records.find(date) == records.end()) {
		cout << "\tNo contact record found on " << date.DatetoString() << "\n\n";
		return;
	}
	records[date].printContacts();
}
bool operator<(const Date& left, const Date& right) {
	if (left.getMonth() < right.getMonth()) return true;
	else if (left.getMonth() == right.getMonth()) {
		return left.getDay() < right.getDay();
	}
	return false;
}
