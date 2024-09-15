#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	int N = 5;

	Zombie *zombies = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}

	delete[] zombies;

	return (0);
}