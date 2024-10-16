#include "MateriaSource.hpp"
#include "Floor.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	if (this == &other) return;

	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (other.materias[i]) {
			this->materias[i] = other.materias[i]->clone();
		} else {
			this->materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this == &other) return *this;

	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (this->materias[i]) {
			delete this->materias[i];
			this->materias[i] = NULL;
		}
		if (other.materias[i]) {
			this->materias[i] = other.materias[i]->clone();
		} else {
			this->materias[i] = NULL;
		}
	}

	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (this->materias[i]) {
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!this->materias[i]) {
			this->materias[i] = m;
			break;
		}
	}

	Floor::GetInstance()->dropMateria(m);
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (this->materias[i] && this->materias[i]->getType() == type) {
			return this->materias[i]->clone();
		}
	}
	return NULL;
}