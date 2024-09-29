#include "ClapTrap.hpp"

int main() {
	ClapTrap heechoi("heechoi");
	ClapTrap dongclee("dongclee");

	heechoi.attack("dongclee");
	dongclee.takeDamage(3);
	dongclee.beRepaired(2);

	dongclee.attack("heechoi");
	heechoi.takeDamage(5);
	heechoi.beRepaired(2);
	heechoi.takeDamage(9);
	heechoi.beRepaired(2);

	return 0;
}
