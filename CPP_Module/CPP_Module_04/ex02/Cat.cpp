#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->type = other.type;
	delete this->brain;
	this->brain = new Brain(*other.brain);

	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;

	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Cat sound: " << "meow meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}