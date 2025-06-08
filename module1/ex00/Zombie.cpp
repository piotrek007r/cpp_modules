#include "repertory.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " was destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name;
	std::cout << " BraiiiiiiinnnzzzZ" << std::endl;
}