#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "---- TEST 1 ----" << std::endl;
    FragTrap frag("Fragger");

    frag.attack("enemy1");

    frag.highFivesGuys();

    frag.takeDamage(50);

    frag.beRepaired(40);

	frag.takeDamage(1000);

	frag.highFivesGuys();

    FragTrap frag2("Fraggy");
    ScavTrap scav("Scavy");

    frag2.attack("target1");
    frag2.highFivesGuys();

    scav.guardGate();
    scav.takeDamage(60);

    frag2.beRepaired(20);

    return 0;
}
