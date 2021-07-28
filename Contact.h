#pragma once
#include<string>
#include<iostream>
#include "Time.h"

using namespace std;

class Contact {
private:
	string contactName;
	Time contactTime;

public:
	Contact(string, Time);

	string getContactName() const;
	Time getContactTime() const;

	void setContactName(string);
	void setContactTime(const Time&);

	void printContact();

	void operator=(const Contact& t);
};

