//
// Created by HeeSung Choi on 11/12/24.
//

#include "AForm.hpp"

AForm::AForm(): name("default"), signGrade(0), execGrade(0) {}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other) return *this;

	return *this;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
		: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE) {
		throw AForm::GradeTooHighException();
	}

	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE) {
		throw AForm::GradeTooLowException();
	}
}


AForm::AForm(const AForm &other)
		: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade) {
		throw AForm::GradeTooLowException();
	}

	if (isSigned) {
		std::cout << "Form is already signed." << std::endl;
		return;
	}

	isSigned = true;
}

const std::string &AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecGrade() const {
	return execGrade;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form is not signed.";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form name: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: "
		<< form.getExecGrade() << ", Signed: " << form.getIsSigned();

	return out;
}
