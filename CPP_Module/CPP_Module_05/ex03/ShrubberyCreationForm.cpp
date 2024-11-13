//
// Created by HeeSung Choi on 11/12/24.
//

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::NAME = "shrubbery creation";

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm(NAME, REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm(NAME, REQUIRED_GRADE_TO_SIGN, REQUIRED_GRADE_TO_EXEC), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other)
		return (*this);

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();

	std::ofstream file;
	file.open((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("File open error");
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file.close();
}
