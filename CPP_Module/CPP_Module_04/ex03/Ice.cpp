#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const & src): AMateria(src) {
	if (this == &src) return ;

	*this = src;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &rhs) {
	if (this == &rhs) return *this;

	this->_type = rhs._type;
	this->_xp = rhs._xp;

	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}