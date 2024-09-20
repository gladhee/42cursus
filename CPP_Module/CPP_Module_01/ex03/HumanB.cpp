#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack(void) {
	if (this->_weapon == NULL) {
		std::cout << this->_name << " has no weapon to attack with" << std::endl;

		return;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}