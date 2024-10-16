#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

private:
	static const int INVENTORY_SIZE = 4;
	std::string name;
 	AMateria* inventory[INVENTORY_SIZE];

public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
