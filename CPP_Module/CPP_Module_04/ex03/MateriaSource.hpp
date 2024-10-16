#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	static const int MAX_MATERIAS = 4;
	AMateria* materias[MAX_MATERIAS];


public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};

#endif
