#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {

	std::cout << "Brain copy constructor called" << std::endl;

	if (this == &other) return;

	for (int i = 0; i < MAX_IDEAS; i++) {
		this->ideas[i] = other.ideas[i];
	}

}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	for (int i = 0; i < MAX_IDEAS; i++) {
		this->ideas[i] = other.ideas[i];
	}

	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(const int index) const {
	if (index < 0 || index >= MAX_IDEAS) return "Invalid index";

	return this->ideas[index];
}

void Brain::setIdea(const int index, const std::string idea) {
	if (index < 0 || index >= MAX_IDEAS) return;

	this->ideas[index] = idea;
}
