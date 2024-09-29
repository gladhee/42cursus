#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	WrongAnimal::operator=(other);

	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat type: " << this->_type << " destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound: " << "meow meow" << std::endl;
}