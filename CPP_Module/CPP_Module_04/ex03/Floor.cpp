#include "Floor.hpp"

Floor *Floor::_floor = NULL;    // static member initialization

Floor::Floor() {
	this->_materia = new MateriaList;
	this->_materia->m = NULL;
	this->_materia->next = NULL;
}


Floor::Floor(const Floor &other) {
	if (this == &other)
		return;
	this->_materia = new MateriaList;
	MateriaList *tmp = other._materia;
	while (tmp) {
		this->_materia->m = tmp->m;
		this->_materia->next = new MateriaList;
		tmp = tmp->next;
	}
}

Floor &Floor::operator=(const Floor &other) {
	if (this == &other)
		return *this;
	discardAllMateria();
	this->_materia = new MateriaList;
	MateriaList *node = other._materia;
	while (node) {
		this->_materia->m = node->m;
		this->_materia->next = new MateriaList;
		node = node->next;
	}
	return *this;
}

Floor::~Floor() {
	discardAllMateria();
	delete this->_materia;
}

bool Floor::hasBeenDropped(AMateria *m) {
	MateriaList *node = Floor::GetInstance()->_materia;
	while (node) {
		if (node->m == m)
			return true;
		node = node->next;
	}
	return false;
}

void Floor::dropMateria(AMateria *m) {
	if (!this->_materia) {
		this->_materia = new MateriaList;
		this->_materia->m = m;
		this->_materia->next = NULL;
		return;
	}
	if (!this->_materia->m) {
		this->_materia->m = m;
		return;
	}
	if (Floor::hasBeenDropped(m))
		return;

	MateriaList *node = this->_materia;
	while (node->next)
		node = node->next;
	MateriaList *newNode = new MateriaList;
	newNode->m = m;
	newNode->next = NULL;
	node->next = newNode;
}

AMateria *Floor::pickUpMateria(const std::string &type) {
	if (!this->_materia || !this->_materia->m)
		return NULL;

	MateriaList *prev = NULL;
	MateriaList *node = this->_materia;
	while (node) {
		if (node->m->getType() == type) {
			AMateria *m = node->m;
			if (!prev)
				this->_materia = node->next;
			else
				prev->next = node->next;
			delete node;
			return m;
		}
		prev = node;
		node = node->next;
	}
	return NULL;
}

void Floor::discardAllMateria() {
	MateriaList *node;
	MateriaList *next;
	node = this->_materia;
	while (node) {
		next = node->next;
		delete node->m;
		delete node;
		node = next;
	}
}

Floor *Floor::GetInstance() {
	if (!Floor::_floor)
		Floor::_floor = new Floor();
	return Floor::_floor;
}

unsigned int Floor::getMateriaCount() const {
	if (!this->_materia || !this->_materia->m)
		return 0;

	unsigned int count = 0;
	MateriaList *node = this->_materia;
	while (node) {
		if (node->m)
			count++;
		node = node->next;
	}
	return count;
}