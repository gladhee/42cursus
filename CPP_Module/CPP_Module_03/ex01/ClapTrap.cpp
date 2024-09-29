#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name <<  " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap "<< other._name << " copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap " << other._name << " assignation operator called" << std::endl;

	if (this == &other) return *this;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (isDeadPrint()) return;

	std::cout << "ClapTrap "<< this->_name
			  << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage!"
			  << std::endl;

	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDeadPrint()) return;

	std::cout << "ClapTrap " << this->_name
			  << " takes " << amount
			  << " points of damage!"
			  << std::endl;

	if (this->_hitPoints < amount) {
		this->_hitPoints = 0;
	} else {
		this->_hitPoints -= amount;
	}

	if (!this->_hitPoints) {
		std::cout << this->_name
				  << " is dead!"
				  << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (isDeadPrint()) return;

	std::cout << "ClapTrap " << this->_name
			  << " is repaired for " << amount
			  << " points of health!"
			  << std::endl;

	this->_hitPoints += amount;
	this->_energyPoints--;
}

bool ClapTrap::isDeadPrint() const {
	if (!this->_hitPoints || !this->_energyPoints) {
		std::cout << this->_name
				  << " is already dead!"
				  << std::endl;

		return true;
	}

	return false;
}
