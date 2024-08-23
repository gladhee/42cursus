#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &phonebook) {}

PhoneBook &phoneBook::operator=(const PhoneBook &phoneBook) {}

void PhoneBook::addContact() {
	Contact contact;

	std::cout << "Enter the first name: ";
	std::cin >> contact.first_name;
	std::cout << "Enter the last name: ";
	std::cin >> contact.last_name;
	std::cout << "Enter the nickname: ";
	std::cin >> contact.nick_name;
	std::cout << "Enter the phone number: ";
	std::cin >> contact.phone_number;
	std::cout << "Enter the darkest secret: ";
	std::cin >> contact.darkest_secret;

}
