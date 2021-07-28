#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Time {

private:
	int hour;
	int min;

public:
	Time();
	Time(int, int);

	void setTime(int, int);
	void setHour(int);
	int getHour() const;
	void setMinute(int);
	int getMinute() const;
	string TimetoString() const;
	Time StringtoTime(string);
	void printTime();
	bool checkTime(string, char) const;

	bool operator==(const Time&);
	void operator=(const Time&);
	bool operator<(const Time&);
	bool operator>(const Time&);
};


