#include "repertory.hpp"

int main()
{
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap gateKeeper("Guardian");

    std::cout << "\n=== Testing Attack ===" << std::endl;
    gateKeeper.attack("Intruder");

    std::cout << "\n=== Testing Guard Mode ===" << std::endl;
    gateKeeper.guardGate();

    std::cout << "\n=== Testing Energy Drain ===" << std::endl;
    gateKeeper.setEnergyPoints(5);
    for (int i = 0; i < 5; ++i)  
        gateKeeper.attack("Dummy");

    std::cout << "\n=== Testing Healing with No Energy ===" << std::endl;
    gateKeeper.beRepaired(10); 

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    ScavTrap copyBot(gateKeeper);

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    ScavTrap assignBot;
    assignBot = gateKeeper;

    std::cout << "\n=== End of Program ===" << std::endl;
    return 0;
}