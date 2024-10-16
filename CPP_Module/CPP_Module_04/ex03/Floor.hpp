#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

typedef struct MateriaList {
	AMateria *m;
	MateriaList *next;
} MateriaList;

class Floor {

private:
	static Floor *floor;
	MateriaList *materia;

	Floor();
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);

	void discardAllMateria();


public:
	virtual ~Floor();

	static Floor *GetInstance();
	void dropMateria(AMateria *);
	static bool hasBeenDropped(AMateria *m);

};

#endif
