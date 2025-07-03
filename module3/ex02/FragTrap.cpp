#include "repertory.hpp"

void FragTrap::attack(const std::string& target)
{
    if((getEnergyPoints() > 0) && (getHitPoints() > 0))
    {
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << "FragTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() 
            << " points of damage" << std::endl;
    }
    else if(getHitPoints() <= 0)
        std::cout << "FragTrap " << getName() << " has no hit points left" << std::endl;
    else if(getEnergyPoints() <= 0)
        std::cout << "FragTrap " << getName() << " has run of energy" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap defoult constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << name << " is boosted!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy assign operator called" << std::endl;
    return *this;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << getName() << "give me high five" << std::endl;
}