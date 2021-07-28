#include "DailyMovement.h"
#include <iostream>

DailyMovement::DailyMovement() {
	contacts = vector<Contact>();
	travels = vector<Travel>();
}

vector<Contact> DailyMovement::getContacts() {
	return contacts;
}
bool DailyMovement::addContact(string contactName, Time& contactTime, int key) {
	for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
		if ((*it).getContactName().compare(contactName) == 0 && (*it).getContactTime() == contactTime) {
			cout << "\tContact already exists" << endl;
			return false;
		}
	}
	contacts.push_back(Contact(contactName, contactTime));
	if (key) {
		cout << "\tContact added" << endl;
	}
	return true;
}
bool DailyMovement::removeContact(string contactName, Time& contactTime) {
	for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
		if ((*it).getContactName().compare(contactName) == 0 && (*it).getContactTime() == contactTime) {
			contacts.erase(it);
			cout << "\tContact removed" << endl;
			return true;
		}
	}
	cout << "\tContact (" << contactName << ", " << contactTime.TimetoString() << ") not exist." << endl;
	return false;
}
bool DailyMovement::changeContact(string oldContactName, Time& oldContactTime, string newContactName, Time& newContactTime) {
	for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
		if ((*it).getContactName().compare(oldContactName) == 0 && (*it).getContactTime() == oldContactTime) {
			(*it).setContactName(newContactName);
			(*it).setContactTime(newContactTime);
			cout << "\tContact changed" << endl;
			return true;
		}
	}
	cout << "\tContact (" << oldContactName << ", " << oldContactTime.TimetoString() << ") not exist." << endl;
	return false;
}
void DailyMovement::printContacts() {
	if (contacts.empty()) {
		cout << "\tNo contact found." << endl;
		return;
	}
	cout << "\t";
	for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
		(*it).printContact();
	}
	cout << endl;
}

vector<Travel> DailyMovement::getTravels() {
	return travels;
}
bool DailyMovement::addTravel(string travelName, Time& arriveTime, Time& departTime, int key) {
	for (vector<Travel>::iterator it = travels.begin(); it != travels.end(); ++it) {
		if ((*it).getTravelName().compare(travelName) == 0 && ((*it).getArriveTime() == arriveTime || (*it).getDepartTime() == departTime)) {
			cout << "\tTravel already exists" << endl;
			return false;
		}
	}
	travels.push_back(Travel(travelName, arriveTime, departTime));
	if (key) {
		cout << "\tTravel added" << endl;
	}
	return true;
}
bool DailyMovement::removeTravel(string travelName, Time& arriveTime, Time& departTime) {
	for (vector <Travel> ::iterator it = travels.begin(); it != travels.end(); ++it) {
		if ((*it).getTravelName().compare(travelName) == 0 && ((*it).getArriveTime() == arriveTime || (*it).getDepartTime() == departTime)) {
			travels.erase(it);
			cout << "\tTravel removed" << endl;
			return true;
		}
	}
	cout << "\tContact (" << travelName << ", " << arriveTime.TimetoString() << ", " << departTime.TimetoString() << ") not exist." << endl;
	return false;
}
bool DailyMovement::changeTravel(string oldTravelName, Time& oldArriveTime, Time& oldDepartTime, string newTravelName, Time& newArriveTime, Time& newDepartTime) {
	for (vector<Travel>::iterator it = travels.begin(); it != travels.end(); ++it) {
		if ((*it).getTravelName().compare(oldTravelName) == 0 && ((*it).getArriveTime() == oldArriveTime || (*it).getDepartTime() == oldDepartTime)) {
			(*it).setTravelName(newTravelName);
			(*it).setArriveTime(newArriveTime);
			(*it).setDepartTime(newDepartTime);
			cout << "\tTravel changed" << endl;
			return true;
		}
	}
	cout << "\tContact (" << oldTravelName << ", " << oldArriveTime.TimetoString() << ", " << oldDepartTime.TimetoString() << ") not exist." << endl;
	return false;
}
void DailyMovement::printTravels() {
	if (travels.empty()) {
		cout << "\tNo travel record found." << endl;
		return;
	}
	cout << "\t";
	for (vector<Travel>::iterator it = travels.begin(); it != travels.end(); ++it) {
		(*it).printTravel();
	}
	cout << endl;
}