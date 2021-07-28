#include "Date.h"

map<int, bool> months31 = { {1,true},{3,true},{5,true},{7,true},{8,true},{10,true},{12,true} };
map<int, bool> months30 = { {4,true},{6,true},{9,true},{11,true} };
int year = 2021;

Date::Date() {
	month = 0; day = 0;
}
Date::Date(int month, int day) {
	this->month = month;
	this->day = day;
}

void Date::setDate(int month, int day) {
	this->month = month;
	this->day = day;
}
void Date::setMonth(int m) {
	month = m;
}
int Date::getMonth() const {
	return month;
}
void Date::setDay(int d) {
	day = d;
}
int Date::getDay() const {
	return day;
}

string Date::DatetoString() const {
	string m = to_string(month);
	if (month < 10) m = "0" + m;
	string d = to_string(day);
	if (day < 10) d = "0" + d;
	return m + "/" + d;
}
Date Date::StringtoDate(string date) {
	int month = stoi(date.substr(0, 2));
	int day = stoi(date.substr(3, 2));
	Date t(month, day);
	return t;
}
void Date::printDate() {
	cout << "(" << this->DatetoString() << ")";
}
bool Date::checkLeapYr(int year) const {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
bool Date::checkDay(int month, int day) const {
	return day < 1 || (months31.find(month) != months31.end() && day > 31)
		|| (months30.find(month) != months30.end() && day > 30)
		|| (month == 2 && checkLeapYr(year) && day > 29) || (month == 2 && day > 28);
}
bool Date::checkDate(string date, char mode, int month) const {
	if (mode == 'm') {
		try {
			int month = stoi(date);
			if (month > 12 || month < 1) {
				throw invalid_argument("");
			}
			return true;
		}
		catch (exception invalid_argument) {
			cout << "\t\tMonth must be between 1 and 12\n\n";
			return false;
		}
	}
	else {
		try {
			int day = stoi(date);
			if (checkDay(month, day)) {
				throw invalid_argument("");
			}
			return true;
		}
		catch (exception invalid_argument) {
			string m = "31";
			if (months30.find(month) != months30.end()) m = "30";
			else if (month == 2) {
				if (checkLeapYr(year)) m = "29";
				else m = "28";
			}
			cout << "\t\tDay must be between 1 and " + m  + "\n\n";
			return false;
		}
	}
}

bool Date::operator==(const Date& d) {
	return this->month == d.month && this->day == d.day;
}
void Date::operator=(const Date& d) {
	setDate(d.month, d.day);
}
bool Date::operator<(const Date& d) {
	if (this->month < d.month) return true;
	else if (this->month == d.month) {
		return this->day < d.day;
	}
	return false;
}


