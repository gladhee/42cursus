#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(): _name("default") {}

Zombie::Zombie(const std::string &name): _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << " bye bye" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << " : " << SOUND << std::endl;
}
