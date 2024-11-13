//
// Created by HeeSung Choi on 11/12/24.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm("RobotomyRequestForm", REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return (*this);

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << "Robotomizing " << target << " wwwwwwwiiiiinnnnnnnnnggggggggg" << std::endl;

	if (attemptRobotization()) {
		std::cout << "Robotomization succeeded." << std::endl;

		return;
	}

	std::cout << "Robotomization failed." << std::endl;
}

bool RobotomyRequestForm::attemptRobotization() const {
	srand(time(0));

	return std::rand() & 1;
}
