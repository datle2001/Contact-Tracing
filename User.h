#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "DailyMovement.h"
#include "Date.h"
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <Windows.h>

class User {
private:
	string fullName;
	map<Date, DailyMovement> records;
	fstream myTravelFile;
	fstream myContactFile;

public:
	User();
	User(string);

	void createCSV(string);
	void closeFile();

	string getName() const;
	void setName(string);
	void updateInfo();
	void printInfo();

	map<Date, DailyMovement> getRecords();
	void addRecord();
	void removeRecord();
	void changeRecord();

	void printAllRecord();
	void printAllTravelRecord();
	void printAllContactRecord();

	void printRecordOn();
	void printTravelRecordOn();
	void printContactRecordOn();

	void addContactToFile(const Date&, string, const Time&);
	void getContactfromFile(string);
	void removeContactfromFile();
	void changeContactinFile();

	void addTravelToFile(const Date&, string, const Time&, const Time&);
	void getTravelfromFile(string);
	void removeTravelfromFile();
	void changeTravelinFile();

	void askDate(string, Date&);
	string askChoice(string);
	string askContact(string);
	string askPlace(string);
	void askTime(Time&);


};

