#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->type = other.type;

	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat sound: " << "meow meow" << std::endl;
}
