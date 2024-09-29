#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal type: " << this->_type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->_type = other._type;

	return *this;
}

Animal::~Animal() {
	std::cout << "Animal type: " << this->_type << " destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound: " << "i'm Animal" << std::endl;
}