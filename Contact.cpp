#include "Contact.h"

Contact::Contact(string contactName, Time contactTime)
	: contactTime(contactTime)
{
	this->contactName = contactName;
}
string Contact::getContactName() const {
	return contactName;
}
Time Contact::getContactTime() const {
	return contactTime;
}
void Contact::setContactName(string contactName) {
	this->contactName = contactName;
}
void Contact::setContactTime(const Time& contactTime) {
	this->contactTime = contactTime;
}

void Contact::printContact() {
	cout << "(" << contactName << ", " << contactTime.TimetoString() << ") ";
}

void Contact::operator=(const Contact& t) {
	this->setContactName(t.getContactName());
	this->setContactTime(t.getContactTime());
}