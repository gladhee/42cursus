//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_FORM_HPP
#define CPP_MODULE_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	static const int MAX_GRADE = 1;
	static const int MIN_GRADE = 150;

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;

	AForm();

	AForm &operator=(const AForm &other);

public:
	AForm(const std::string &name, int signGrade, int execGrade);

	AForm(const AForm &other);

	virtual ~AForm();

	virtual const std::string &getName() const;

	void beSigned(const Bureaucrat &bureaucrat);


	bool getIsSigned() const;

	int getSignGrade() const;

	int getExecGrade() const;


	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif //CPP_MODULE_FORM_HPP
