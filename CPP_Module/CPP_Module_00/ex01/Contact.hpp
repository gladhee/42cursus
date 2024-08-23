#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();

	~Contact();

	Contact(const Contact &contact);

	Contact &operator=(const Contact &contact);


};


#endif