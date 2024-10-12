#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* _inventory[4];


public:
	Character(std::string const & name);
	Character(Character const & src);
	virtual ~Character();

	Character& operator=(Character const & rhs);
};

#endif
