//
// Created by HeeSung Choi on 11/12/24.
//

#include "Form.hpp"

Form::Form(): name("default"), signGrade(0), execGrade(0) {}

Form &Form::operator=(const Form &other) {
	if (this == &other) return *this;

	return *this;
}

Form::Form(const std::string &name, int signGrade, int execGrade)
		: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}

	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &other)
		: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade) {
		throw Form::GradeTooLowException();
	}

	if (isSigned) {
		std::cout << "Form is already signed." << std::endl;
		return;
	}

	isSigned = true;
}

const std::string &Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecGrade() const {
	return execGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form name: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: "
		<< form.getExecGrade() << ", Signed: " << form.getIsSigned();

	return out;
}
