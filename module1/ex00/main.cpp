#include "repertory.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Czesio1");
	randomChump("Czesio2");
	delete (zombie);
	return (0);
}
