#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type) {
	std::cout << "Animal type: " << this->type<< " constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->type= other.type;

	return *this;
}

Animal::~Animal() {
	std::cout << "Animal type: " << this->type<< " destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
