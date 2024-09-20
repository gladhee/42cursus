#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	std::cout << claptrap.getName() << std::endl;
	std::cout << claptrap.getHitPoints() << std::endl;
	std::cout << claptrap.getEnergyPoints() << std::endl;
	std::cout << claptrap.getAttackDamage() << std::endl;

	claptrap2.attack("target");
	claptrap2.takeDamage(15);
	claptrap2.beRepaired(0);

	std::cout << claptrap2.getName() << std::endl;
	std::cout << claptrap2.getHitPoints() << std::endl;
	std::cout << claptrap2.getEnergyPoints() << std::endl;
	std::cout << claptrap2.getAttackDamage() << std::endl;

	claptrap3.attack("target");
	claptrap3.takeDamage(20);
	claptrap3.beRepaired(10);

	std::cout << claptrap3.getName() << std::endl;
	std::cout << claptrap3.getHitPoints() << std::endl;
	std::cout << claptrap3.getEnergyPoints() << std::endl;
	std::cout << claptrap3.getAttackDamage() << std::endl;

	return 0;
}
