#pragma once
#include<string>
#include<iostream>
#include "Time.h"
using namespace std;


class Travel {
private:
	string travelName;
	Time arriveTime;
	Time departTime;

public:
	Travel(string, Time, Time);

	string getTravelName() const;
	void setTravelName(string);

	Time getArriveTime() const;
	void setArriveTime(const Time&);

	Time getDepartTime() const;
	void setDepartTime(const Time&);

	void printTravel();

	void operator=(const Travel&);
};

