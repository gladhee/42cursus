#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("b", 0);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("b", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat c("c", 150);
		c.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat d("d", 1);
		d.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat e("e", 75);
		std::cout << e << std::endl;
		e.decrementGrade();
		std::cout << e << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat f("f", 75);
		std::cout << f << std::endl;
		f.incrementGrade();
		std::cout << f << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}
