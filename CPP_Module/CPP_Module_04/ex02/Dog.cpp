#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->type = other.type;
	delete this->brain;
	this->brain = new Brain(*other.brain);

	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;

	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Dog sound: " << "woof woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}