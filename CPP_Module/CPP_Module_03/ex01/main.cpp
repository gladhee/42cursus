#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "---- TEST 1 ----" << std::endl;
    ClapTrap clap("Clappy");

    clap.attack("target1");

    clap.takeDamage(5);

    clap.beRepaired(3);

    std::cout << "\n---- TEST 2 ----" << std::endl;
    ScavTrap scav("Serena");

    scav.attack("enemy1");

    scav.guardGate();

    scav.takeDamage(60);

    scav.beRepaired(40);

	scav.takeDamage(1000);

	scav.guardGate();

    std::cout << "\n---- TEST 3 ----" << std::endl;
    ClapTrap clap2("Clappy2");
    ScavTrap scav2("Scavy2");

    clap2.attack("target3");
    clap2.takeDamage(7);
    clap2.beRepaired(5);

    scav2.guardGate();
    scav2.takeDamage(40);

    clap2.attack("target4");

    scav2.beRepaired(25);

    return 0;
}
