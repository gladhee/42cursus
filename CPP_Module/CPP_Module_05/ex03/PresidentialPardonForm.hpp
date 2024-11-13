//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULE_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	static const std::string NAME;
	static const int REQUIRED_GRADE_TO_EXEC = 25;
	static const int REQUIRED_GRADE_TO_SIGN = 5;

private:
	const std::string target;

	PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

public:
	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm(const PresidentialPardonForm &other);

	virtual ~PresidentialPardonForm();


	void execute(const Bureaucrat &executor) const;

};


#endif //CPP_MODULE_PRESIDENTIALPARDONFORM_HPP
