//
// Created by Heesung Choi on 11/13/24.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	if (this == &other) return;

	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	if (this == &other) return *this;

	return *this;
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	AForm *(*form[3])(const std::string &) = {
			Intern::createShrubberyCreationForm,
			Intern::createRobotomyRequestForm,
			Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++) {
		AForm *selectedForm = form[i](target);
		if (equals(selectedForm->getName(), formName)) {
			std::cout << "Intern creates " << selectedForm->getName() << std::endl;

			return selectedForm;
		}
		delete selectedForm;
	}

	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

bool Intern::equals(const std::string &s1, const std::string &s2) {
	return s1 == s2;
}
