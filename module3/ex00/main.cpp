#include "repertory.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap bot1("BotAlpha");
    ClapTrap bot2("BotBeta");

    std::cout << "\n=== Basic Attack ===" << std::endl;
    bot1.attack("BotBeta");
    bot2.takeDamage(0); 

    std::cout << "\n=== Heal After Attack ===" << std::endl;
    bot1.beRepaired(3);

    std::cout << "\n=== Damage Until Destroyed ===" << std::endl;
    for (int i = 0; i < 5; ++i)
        bot2.takeDamage(3); 
    std::cout << "\n=== Try to Attack with No HP or Energy ===" << std::endl;
    ClapTrap bot3("DeadBot");
    for (int i = 0; i < 10; ++i)
        bot3.attack("Target");
    bot3.attack("StillTrying"); 

    std::cout << "\n=== Heal with No Energy ===" << std::endl;
    bot3.beRepaired(5); 

    std::cout << "\n=== Done ===" << std::endl;

    return 0;
}
