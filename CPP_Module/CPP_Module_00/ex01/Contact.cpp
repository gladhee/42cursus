#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return (this->_firstName);
}

std::string Contact::getLastName() {
	return (this->_lastName);
}

std::string Contact::getNickname() {
	return (this->_nickname);
}

std::string Contact::getPhoneNumber() {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() {
	return (this->_darkestSecret);
}

std::string Contact::getShortened(int name) {
	std::string str;

	switch (name) {
		case 0:
			str = this->getFirstName();
			break;
		case 1:
			str = this->getLastName();
			break;
		case 2:
			str = this->getNickname();
			break;
		default:
			throw std::exception();
	}

	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}

	return (str);
}