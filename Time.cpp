#include "Time.h"

Time::Time() {
	min = 0; hour = 0;
}
Time::Time(int hour, int min) {
	this->hour = hour;
	this->min = min;
}

void Time::setTime(int hour, int min) {
	if (checkTime(to_string(hour), 'h')) {
		this->hour = hour;
	}
	if (checkTime(to_string(min), 'm')) {
		this->min = min;
	}
}

void Time::setHour(int h) {
	hour = h;
}
int Time::getHour() const {
	return hour;
}
void Time::setMinute(int m) {
	min = m;
}
int Time::getMinute() const {
	return min;
}

string Time::TimetoString() const {
	string h = to_string(hour);
	if (hour < 10) h = "0" + h;
	string m = to_string(min);
	if (min < 10) m = "0" + m;
	return h + ":" + m;
}
Time Time::StringtoTime(string time) {
	int hour = stoi(time.substr(0, 2));
	int min = stoi(time.substr(3, 2));
	Time t(hour, min);
	return t;
}
void Time::printTime() {
	cout << "(" << this->TimetoString() << ")";
}

bool Time::checkTime(string time, char mode) const {
	if (mode == 'h') {
		try {
			int hour = stoi(time);
			if (hour > 23 || hour < 0) {
				throw invalid_argument("");
			}
			return true;
		}
		catch (exception invalid_argument) {
			cout << "\t\tHour must be between 0 and 23\n\n";
			return false;
		}
	}
	else {
		try {
			int min = stoi(time);
			if (min > 59 || min < 0) {
				throw invalid_argument("");
			}
			return true;
		}
		catch (exception invalid_argument) {
			cout << "\t\tMin must be between 0 and 59\n\n";
			return false;
		}
	}
}

bool Time::operator==(const Time& t) {
	return this->hour == t.hour && this->min == t.min;
}
void Time::operator=(const Time& t) {
	setTime(t.hour, t.min);
}
bool Time::operator<(const Time& t) {
	if (this->hour < t.hour) return true;
	else if (this->hour == t.hour) {
		return this->min < t.min;
	}
	return false;
}
bool Time::operator>(const Time& t) {
	if (this->hour > t.hour) return true;
	else if (this->hour == t.hour) {
		return this->min > t.min;
	}
	return false;
}

