#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const Contact &contact) {
	*this = contact;
}

Contact &Contact::operator=(const Contact &contact) {
	this.
	if (this != &contact) {
		this->first_name = contact.first_name;
		this->last_name = contact.last_name;
		this->nick_name = contact.nick_name;
		this->phone_number = contact.phone_number;
		this->darkest_secret = contact.darkest_secret;
	}
	return (*this);
}
