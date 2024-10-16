#include "Floor.hpp"

Floor *Floor::floor = NULL;    // static member initialization

Floor::Floor() {
	this->materia = new MateriaList;
	this->materia->m = NULL;
	this->materia->next = NULL;
}


Floor::Floor(const Floor &other) {
	if (this == &other)
		return;
	this->materia = new MateriaList;
	MateriaList *tmp = other.materia;
	while (tmp) {
		this->materia->m = tmp->m;
		this->materia->next = new MateriaList;
		tmp = tmp->next;
	}
}

Floor &Floor::operator=(const Floor &other) {
	if (this == &other)
		return *this;
	this->discardAllMateria();
	this->materia = new MateriaList;
	MateriaList *node = other.materia;
	while (node) {
		this->materia->m = node->m;
		this->materia->next = new MateriaList;
		node = node->next;
	}

	return *this;
}

Floor::~Floor() {
	discardAllMateria();
	delete this->materia;
}

bool Floor::hasBeenDropped(AMateria *m) {
	MateriaList *node = GetInstance()->materia;
	while (node) {
		if (node->m == m)
			return true;
		node = node->next;
	}
	return false;
}

void Floor::dropMateria(AMateria *m) {
	if (!this->materia) {
		this->materia = new MateriaList;
		this->materia->m = m;
		this->materia->next = NULL;
		return;
	}
	if (!this->materia->m) {
		this->materia->m = m;
		return;
	}
	if (hasBeenDropped(m)) return;

	MateriaList *node = this->materia;
	while (node->next)
		node = node->next;
	MateriaList *newNode = new MateriaList;
	newNode->m = m;
	newNode->next = NULL;
	node->next = newNode;
}

void Floor::discardAllMateria() {
	MateriaList *node;
	MateriaList *next;
	node = this->materia;

	while (node) {
		next = node->next;
		delete node->m;
		delete node;
		node = next;
	}
}

Floor *Floor::GetInstance() {
	if (!Floor::floor)
		Floor::floor = new Floor();

	return Floor::floor;
}
