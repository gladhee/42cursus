//
// Created by Heesung Choi on 11/13/24.
//

#ifndef CPP_MODULE_INTERN_HPP
#define CPP_MODULE_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

private:
	bool equals(const std::string &s1, const std::string &s2);

public:
	Intern();

	Intern(const Intern &other);

	virtual ~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);

	static AForm *createShrubberyCreationForm(const std::string &target);

	static AForm *createRobotomyRequestForm(const std::string &target);

	static AForm *createPresidentialPardonForm(const std::string &target);

	class FormNotFoundException : public std::exception {
		virtual const char *what() const throw();
	};

};

#endif //CPP_MODULE_INTERN_HPP
