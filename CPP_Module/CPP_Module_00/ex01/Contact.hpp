#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#define FIRST_NAME 0
#define LAST_NAME 1
#define NICKNAME 2

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	~Contact();

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	std::string getShortened(int name);
};

#endif