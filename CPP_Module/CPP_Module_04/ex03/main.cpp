#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void check(void)
{
	system("leaks interface");
}

int main() {
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp_ice = NULL;
	AMateria* tmp_cure = NULL;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp_ice = src->createMateria("ice");
	me->equip(tmp_ice);
	tmp_cure = src->createMateria("cure");
	me->equip(tmp_cure);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);

	delete tmp_ice;
	tmp_ice = NULL;

	delete tmp_cure;
	tmp_cure = NULL;

	delete bob;
	delete me;
	delete src;

	return 0;
}