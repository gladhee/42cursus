#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_contactIndex;

	void	setContact(Contact &contact);
	void	printContacts();


public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();
	bool isValidInput(std::string input);
};

#endif