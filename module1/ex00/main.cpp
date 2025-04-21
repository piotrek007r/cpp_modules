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

	zombie = newZombie("Czesio1");
	randomChump("Czesio2");
	delete (zombie);
	return (0);
}
