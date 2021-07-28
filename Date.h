#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <map> 

using namespace std;

class Date {

private:
	int month;
	int day;

public:
	Date();
	Date(int, int);

	void setDate(int, int);
	void setMonth(int);
	int getMonth() const;
	void setDay(int);
	int getDay() const;
	string DatetoString() const;
	Date StringtoDate(string);
	void printDate();
	bool checkDate(string, char, int) const;
	bool checkDay(int, int) const;
	bool checkLeapYr(int) const;

	bool operator==(const Date&);
	void operator=(const Date&);
	bool operator<(const Date&);
};

