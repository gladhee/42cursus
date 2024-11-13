//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULE_ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	static const std::string NAME;
	static const int REQUIRED_GRADE_TO_EXEC = 72;
	static const int REQUIRED_GRADE_TO_SIGN = 45;

private:
	const std::string target;

	RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	bool attemptRobotization() const;

public:
	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm(const RobotomyRequestForm &other);

	virtual ~RobotomyRequestForm();


	void execute(const Bureaucrat &executor) const;

};


#endif //CPP_MODULE_ROBOTOMYREQUESTFORM_HPP
