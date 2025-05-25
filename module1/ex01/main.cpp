#include "repertory.hpp"

int main()
{
    Zombie *first_zombie;

    first_zombie = zombieHorde(4, "Czesio");
    delete[] first_zombie;
}