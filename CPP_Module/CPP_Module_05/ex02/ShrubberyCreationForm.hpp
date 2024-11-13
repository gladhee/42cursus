//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

public:
	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const &executor) const;

};


#endif //CPP_MODULE_SHRUBBERYCREATIONFORM_HPP
