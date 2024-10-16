#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &other): AMateria(other.getType()) {}

Cure &Cure::operator=(const Cure &other) {
	if (this == &other) return *this;

	this->type = other.type;

	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}