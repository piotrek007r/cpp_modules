#include "repertory.hpp"

void ScavTrap::attack(const std::string& target)
{
    if((getEnergyPoints() > 0) && (getHitPoints() > 0))
    {
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() 
            << " points of damage" << std::endl;
    }
    else if(getHitPoints() <= 0)
        std::cout << "ScavTrap " << getName() << " has no hit points left" << std::endl;
    else if(getEnergyPoints() <= 0)
        std::cout << "ScavTrap " << getName() << " has run of energy" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap defoult constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << name << " is boosted!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assign operator called" << std::endl;
    return *this;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

