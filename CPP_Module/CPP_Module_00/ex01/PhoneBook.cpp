#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
	_contactIndex = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	Contact contact;

	this->setContact(contact);
	if (_contactIndex == 8) {
		for (int i = 0; i < 7; i++) {
			_contacts[i] = _contacts[i + 1];
		}
		_contactIndex--;
	}
	this->_contacts[_contactIndex] = contact;
	_contactIndex++;
}

void PhoneBook::searchContact() {
	std::stgring input;
	int index;

	this->printContacts();
	if (_contactIndex == 0) {
		return;
	}
	std::cout << "Enter index of the contact: ";
	std::cin >> index;

	if (std::cin.eof()) throw std::exception();

	if (std::cin.fail() || index < 0 || index >= _contactIndex) {
		std::cin.clear();
		clearerr(stdin);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
		return;
	}

	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::setContact(Contact &contact) {
	std::string input;

	std::cout << "Enter first name: ";
	std::cin >> input;
	if (std::cin.eof()) throw std::exception();
	contact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::cin >> input;
	if (std::cin.eof()) throw std::exception();
	contact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::cin >> input;
	if (std::cin.eof()) throw std::exception();
	contact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::cin >> input;
	if (std::cin.eof()) throw std::exception();
	contact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::cin >> input;
	if (std::cin.eof()) throw std::exception();
	contact.setDarkestSecret(input);

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::printContacts() {
	std::cout << "+-------------------------------------------+" << std::endl
			  << "|     index|first name| last name|  nickname|" << std::endl
			  << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < this->_contactIndex; i++) {
		std::cout << "|"
				  << std::setw(10) << i << "|"
				  << std::setw(10) << this->_contacts[i].getShortened(FIRST_NAME) << "|"
				  << std::setw(10) << this->_contacts[i].getShortened(LAST_NAME) << "|"
				  << std::setw(10) << this->_contacts[i].getShortened(NICKNAME) << "|"
				  << std::endl;
	}
	if (this->_contactIndex > 0) {
		std::cout << "+-------------------------------------------+" << std::endl;
	}
}