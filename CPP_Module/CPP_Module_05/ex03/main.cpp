#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {

	AForm* rrf;
	Intern someRandomIntern;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->getName();
		Bureaucrat b("Bender", 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	AForm* rrf2;
	try {
		rrf2 = someRandomIntern.makeForm("presidentialpardon", "Bender");
		rrf2->getName();
		Bureaucrat b("Bender", 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	delete rrf2;

	return (0);
}
