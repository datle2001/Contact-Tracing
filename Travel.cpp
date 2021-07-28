#include "Travel.h"

using namespace std;

Travel::Travel(string travelName, Time arriveTime, Time departTime)
	: arriveTime(arriveTime), departTime(departTime)
{
	this->travelName = travelName;
}

string Travel::getTravelName() const {
	return travelName;
}
Time Travel::getArriveTime() const {
	return arriveTime;
}
Time Travel::getDepartTime() const {
	return departTime;
}
void Travel::setTravelName(string travelName) {
	this->travelName = travelName;
}
void Travel::setArriveTime(const Time& arriveTime) {
	this->arriveTime = arriveTime;
}
void Travel::setDepartTime(const Time& departTime) {
	this->departTime = departTime;
}
void Travel::printTravel() {
	cout << "(" << travelName << ", " << arriveTime.TimetoString() << ", " << departTime.TimetoString() << ") ";
}

void Travel::operator=(const Travel& t) {
	this->setTravelName(t.getTravelName());
	this->setArriveTime(t.getArriveTime());
	this->setDepartTime(t.getDepartTime());
}