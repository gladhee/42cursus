#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;

	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;

	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;

	if (this == &other) {
		return (*this);
	}
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	return ideas[index];
}