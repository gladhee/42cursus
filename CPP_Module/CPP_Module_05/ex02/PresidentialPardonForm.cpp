//
// Created by HeeSung Choi on 11/12/24.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("PresidentialPardonForm", REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other)
		return (*this);
	return (*this);}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
