#include "repertory.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombie = new Zombie[N];

    Zombie *first_zombie = zombie;
    
    for(int i = 0; i < N; i++)
    {
        zombie->setName(name);
        zombie->annouce();
        zombie++;
    }

    return first_zombie;
}