//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_BUREAUCRAT_HPP
#define CPP_MODULE_BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	static const int MAX_GRADE = 1;
	static const int MIN_GRADE = 150;

private:
	const std::string  name;
	int grade;

	Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);


public:
	Bureaucrat(const std::string &name, int grade);

	Bureaucrat(const Bureaucrat &other);

	~Bureaucrat();


	void incrementGrade();

	void decrementGrade();

	void signForm(AForm &form);

	void executeForm(const AForm & form) const;

	const std::string &getName() const;

	int getGrade() const;


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif //CPP_MODULE_BUREAUCRAT_HPP