#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(Character const & src) {
	if (this == &src) return;


	*this = src;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
}

Character& Character::operator=(Character const & rhs) {
	if (this == &rhs) return *this;

	_name = rhs._name;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
		_inventory[i] = rhs._inventory[i]->clone();
	}

	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_inventory[idx]) return;

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !_inventory[idx]) return;

	_inventory[idx]->use(target);
}
