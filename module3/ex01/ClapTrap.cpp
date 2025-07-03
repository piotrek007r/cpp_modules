#include "repertory.hpp"

void ClapTrap::attack(const std::string& target)
{
    if((this->energyPoints > 0) && (this->hitPoints > 0))
    {
        this->energyPoints = this->energyPoints - 1;
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << this->attackDamage 
            << " points of damage" << std::endl;
    }
    else if(this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " has no hit points left" << std::endl;
    else if(this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " has run of energy" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if((this->energyPoints > 0) && (this->hitPoints > 0))
    {
        this->energyPoints = this->energyPoints - 1;
        this->hitPoints = this->hitPoints + amount;
        std::cout << "ClapTrap " << this->name << " has healed for " << amount << ", and now have " 
            << this->hitPoints << " hit points" << std::endl;
    }
    else if(this->hitPoints <= 0)
        std::cout << "ClapTrap " << name << " has no hit points left" << std::endl;
    else if(this->energyPoints <= 0)
        std::cout << "ClapTrap " << name << " has run of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints = this->hitPoints - amount;
    std::cout << "ClapTrap " << this->name << " recived " << amount << " damage, and now have " 
        << this->hitPoints << " hit points" << std::endl;  
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;
}

std::string ClapTrap::getName()
{
    return this->name;
}

int ClapTrap::getHitPoints()
{
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints()
{
    return this->energyPoints;
}

int ClapTrap::getAttackDamage()
{
    return this->attackDamage;
}

ClapTrap::ClapTrap() 
{
    this->name = "default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->name = other.name;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name; 
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
    std::cout << "ClapTrap copy assign operator called" << std::endl;

}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " was destroyed" << std::endl;
}

