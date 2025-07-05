#include "repertory.hpp"

int main()
{
    DiamondTrap monster("monster");

    monster.whoAmI();  // Check name suffix and base name

    std::cout << "AtackDMG: " << monster.getAttackDamage() << std::endl;  // Should be ScavTrap energy (50)
    std::cout << "Energy: " << monster.getEnergyPoints() << std::endl;  // Should be ScavTrap energy (50)
    std::cout << "HP: " << monster.getHitPoints() << std::endl;         // Should be FragTrap HP (100)

    monster.attack("Intruder");  // Should call ScavTrap attack

    DiamondTrap copyBot(monster);
    copyBot.whoAmI();  // Confirm copy constructor copies correctly
    std::cout << "AtackDMG: " << copyBot.getAttackDamage() << std::endl;  // Should be ScavTrap energy (50)
    std::cout << "Energy: " << copyBot.getEnergyPoints() << std::endl;  // Should be ScavTrap energy (50)
    std::cout << "HP: " << copyBot.getHitPoints() << std::endl;         // Should be FragTrap HP (100)


    return 0;
}