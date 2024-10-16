#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

typedef struct MateriaList {
	AMateria *m;
	MateriaList *next;
} MateriaList;

class Floor {

private:
	static Floor *_floor;
	MateriaList *_materia;

	void discardAllMateria();

	Floor();

	Floor(const Floor &);

	Floor &operator=(const Floor &);


public:
	virtual ~Floor();

	static Floor *GetInstance();

	void dropMateria(AMateria *);

	AMateria *pickUpMateria(std::string const &type);

	unsigned int getMateriaCount() const;

	static bool hasBeenDropped(AMateria *m);

};

#endif
