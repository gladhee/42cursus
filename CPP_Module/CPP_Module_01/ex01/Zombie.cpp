#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie::Zombie(): _name("Zombie") {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << " bye bye" << std::endl;
}

Zombie::Zombie(const Zombie &zombie) {
	*this = zombie;
}

Zombie &Zombie::operator=(const Zombie &zombie) {
	if (this != &zombie) {
		this->_name = zombie._name;
	}

	return (*this);
}

void Zombie::announce(void) {
	std::cout << this->_name << " : " << SOUND << std::endl;
}

void Zombie::setName(std::string name, int idx) {
	std::stringstream ss ;

	ss << idx;
	this->_name = name + ss.str();
}