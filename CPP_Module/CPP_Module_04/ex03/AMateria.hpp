#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;


public:
	AMateria(std::string const & type);

	//
	AMateria();
	AMateria(AMateria const & src);
	AMateria& operator=(AMateria const & rhs);
	virtual ~AMateria();

	std::string const & getType() const;  //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};