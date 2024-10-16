#include "Character.hpp"
#include "Floor.hpp"

Character::Character(): name("default") {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string name): name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other): name(other.name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (other.inventory[i]) {
			this->inventory[i] = other.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character &other) {
	if (this == &other) return *this;

	this->name = other.name;

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
		}
		if (other.inventory[i]) {
			this->inventory[i] = other.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}

	return *this;
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
		}
	}
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			break;
		}
	}

	Floor::GetInstance()->dropMateria(m);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->inventory[idx]) return;

	Floor::GetInstance()->dropMateria(this->inventory[idx]);
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->inventory[idx]) return;

	this->inventory[idx]->use(target);
}
