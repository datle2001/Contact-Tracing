#pragma once
#include <string>
#include <vector>
#include "Travel.h"
#include "Contact.h"

using namespace std;
class DailyMovement {
private:
	vector<Contact> contacts;
	vector<Travel> travels;

public:
	DailyMovement();

	vector<Contact> getContacts();
	bool addContact(string, Time&, int key);
	bool removeContact(string, Time&);
	bool changeContact(string, Time&, string, Time&);
	void printContacts();

	vector<Travel> getTravels();
	bool addTravel(string, Time&, Time&, int key);
	bool removeTravel(string, Time&, Time&);
	bool changeTravel(string, Time&, Time&, string, Time&, Time&);
	void printTravels();
};

