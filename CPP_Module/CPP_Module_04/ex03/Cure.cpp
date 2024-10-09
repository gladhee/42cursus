#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria(src) {
	if (this == &src) return;

	*this = src;
}

Cure::~Cure() {}

Cure& Cure::operator=(Cure const & rhs) {
	if (this == &rhs) return *this;

	this->_type = rhs._type;
	this->_xp = rhs._xp;

	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
