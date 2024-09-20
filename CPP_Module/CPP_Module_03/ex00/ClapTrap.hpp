#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;


public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
	int getHitPoints();
	int getEnergyPoints();
	int getAttackDamage();
};

#endif
