#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat berau("beru", 1);
	ShrubberyCreationForm form("houssam");
	RobotomyRequestForm form2("Robot");
	PresidentialPardonForm form3("Zaphod Beeblebrox");

	berau.signForm(form);
	berau.executeForm(form);

	berau.signForm(form2);
	berau.executeForm(form2);

	berau.signForm(form3);
	berau.executeForm(form3);

	Bureaucrat berau2("beru2", 150);
	ShrubberyCreationForm form4("houssam2");
	RobotomyRequestForm form5("Robot");
	PresidentialPardonForm form6("Zaphod Beeblebrox");

	berau2.signForm(form4);
	berau2.executeForm(form4);

	berau2.signForm(form5);
	berau2.executeForm(form5);

	berau2.signForm(form6);
	berau2.executeForm(form6);

	return (0);
}
