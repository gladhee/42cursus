#include "AMateria.hpp"

AMateria::AMateria(): type("default") {}

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(const AMateria &other): type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this == &other) return *this;

	this->type = other.type;

	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}