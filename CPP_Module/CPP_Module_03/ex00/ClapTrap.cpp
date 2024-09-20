#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap parameter constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap " << this->getName();
	std::cout << "assignation operator" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->_name;
	std::cout << "attacks " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this.)
	std::cout << "ClapTrap " << this->_name;
	std::cout << "takes " << amount;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << "has no energy points to repair!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << "has been repaired for " << amount;
	std::cout << " points of health!" << std::endl;
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
}

std::string ClapTrap::getName() {
	return this->_name;
}

int ClapTrap::getHitPoints() {
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() {
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() {
	return this->_attackDamage;
}
