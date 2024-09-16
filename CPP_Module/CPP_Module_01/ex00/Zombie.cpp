#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	this->_name = "default";
}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

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