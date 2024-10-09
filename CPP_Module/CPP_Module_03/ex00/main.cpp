#include "ClapTrap.hpp"

int main() {
	std::cout << "---- TEST 1: Creating ClapTrap and basic functionality ----" << std::endl;
    ClapTrap clap("Clappy");

    clap.attack("target1");

    clap.takeDamage(5);

    clap.beRepaired(3);

	clap.takeDamage(1000);

	clap.attack("target2");

	return 0;
}
