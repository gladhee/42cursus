#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int		index;


public:
	PhoneBook();

	~PhoneBook();

	PhoneBook(const PhoneBook &phonebook);

	PhoneBook &operator=(const PhoneBook &phonebook);

	void addContact();

	void searchContact();


};