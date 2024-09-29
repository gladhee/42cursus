#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;

	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "ScavTrap " << other._name << " copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap " << other._name << " assignation operator called" << std::endl;

	if (this == &other) return *this;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (isDeadPrint()) return;

	std::cout << "ScavTrap " << this->_name
			  << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage!"
			  << std::endl;

	this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
	if (isDeadPrint()) return;

	std::cout << "ScavTrap " << this->_name
			  << " has entered in Gate keeper mode"
			  << std::endl;

	this->_energyPoints -= 1;
}