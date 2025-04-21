#include "repertory.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie;

	zombie.setName(name);
	zombie.announce();
}

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie();
	zombie->setName(name);
	zombie->announce();
	return (zombie);
}

int	main(void)
{
	Zombie	*zombie;

	randomChump("Czesio");
	zombie = newZombie("Czesio2");
	delete (zombie);
	return (0);
}
