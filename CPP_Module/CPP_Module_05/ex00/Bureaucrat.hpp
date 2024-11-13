//
// Created by HeeSung Choi on 11/12/24.
//

#ifndef CPP_MODULE_BUREAUCRAT_HPP
#define CPP_MODULE_BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {

	static const int MAX_GRADE = 1;
	static const int MIN_GRADE = 150;

private:
	std::string const name;
	int grade;

	Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);


public:
	Bureaucrat(const Bureaucrat &other);

	Bureaucrat(const std::string &name, int grade);

	~Bureaucrat();


	void incrementGrade();

	void decrementGrade();


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
