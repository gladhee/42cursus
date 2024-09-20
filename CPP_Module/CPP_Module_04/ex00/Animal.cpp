#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	if (this != &other)
		*this = other;

	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}