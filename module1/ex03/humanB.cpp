#include "repertory.hpp"

HumanB::HumanB(str name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
