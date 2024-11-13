#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);
	Bureaucrat c("C", 75);

	Form f("F", 1, 1);
	Form g("G", 1, 1);
	Form h("H", 75, 75);

	try {
		Form i("I", 151, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form j("J", 1, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	a.signForm(f);
	a.signForm(f);
	b.signForm(g);

	b.signForm(h);

	return 0;
}
