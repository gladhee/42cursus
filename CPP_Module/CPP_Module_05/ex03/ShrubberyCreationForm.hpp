//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

	static const std::string NAME;
	static const int REQUIRED_GRADE_TO_EXEC = 137;
	static const int REQUIRED_GRADE_TO_SIGN = 145;

private:
	const std::string target;

	ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

public:
	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	virtual ~ShrubberyCreationForm();


	virtual void execute(const Bureaucrat &executor) const;

};


#endif //CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
