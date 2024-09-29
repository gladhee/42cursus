#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;


}

Dog::Dog(const Dog &other): Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	Animal::operator=(other);

	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog sound: " << "woof woof" << std::endl;
}