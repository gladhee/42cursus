//
// Created by HeeSung Choi on 11/12/24.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name(name), grade(grade) {
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}

	if (grade > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade()) {
	if (this == &other) {
		return;
	}

	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other) return *this;

	this->grade = other.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}

	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}

	this->grade++;
}

void Bureaucrat::signForm(Form &form) {
	if (form.getIsSigned()) {
		std::cout << form.getName() << " is already signed." << std::endl;

		return;
	}

	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;

		return;
	}

	std::cout << this->name << " signed " << form.getName() << "." << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return out;
}
