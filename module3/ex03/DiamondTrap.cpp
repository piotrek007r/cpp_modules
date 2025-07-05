#include "repertory.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap is now in Gate keeper mode" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->name = other.name;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "DiamondTrap copy assign operator called" << std::endl;
    return *this;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->name = name + "_clap_name";
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setHitPoints(FragTrap::getHitPoints());
    setAttackDamage(FragTrap::getAttackDamage());
}

std::string DiamondTrap::getName()
{
    return this->name;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap name is: " << ClapTrap::getName() << std::endl;
    std::cout << "DiamondTrap name is: " << this->name << std::endl;
}