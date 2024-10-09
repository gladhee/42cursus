#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;

	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructor called" << std::endl;

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap " << other._name << " copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap " << other._name << " assignation operator called" << std::endl;

	if (this == &other) return *this;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (isDeadPrint()) return;

	std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
}