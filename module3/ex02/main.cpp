#include "repertory.hpp"

int main()
{
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap fragman("Guardian");
    std::cout << "AtackDMG: " << fragman.getAttackDamage() << std::endl;  // Should be 30
    std::cout << "Energy: " << fragman.getEnergyPoints() << std::endl;  // Should be 100
    std::cout << "HP: " << fragman.getHitPoints() << std::endl;         // Should be 100

    std::cout << "\n=== Testing Attack ===" << std::endl;
    fragman.attack("Intruder");

    std::cout << "\n=== Testing H5 request ===" << std::endl;
    fragman.highFivesGuys();

    std::cout << "\n=== Testing Energy Drain ===" << std::endl;
    fragman.setEnergyPoints(5);
    for (int i = 0; i < 5; ++i)  
        fragman.attack("Dummy");

    std::cout << "\n=== Testing Healing with No Energy ===" << std::endl;
    fragman.beRepaired(10);  

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    FragTrap copyBot(fragman);

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    FragTrap assignBot;
    assignBot = fragman;

    std::cout << "\n=== End of Program ===" << std::endl;
    return 0;
}