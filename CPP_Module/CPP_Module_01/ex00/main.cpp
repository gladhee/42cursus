#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main() {
	Zombie *zombie;

	randomChump("heechoi");
	randomChump("Zombie2");
	randomChump("Zombie3");
	randomChump("Zombie4");

	zombie = newZombie("heechoi2");
	zombie->announce();
	delete zombie;

	zombie = newZombie("Zombie5");
	zombie->announce();
	delete zombie;



	return (0);
}