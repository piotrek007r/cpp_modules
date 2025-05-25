#include "repertory.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
    std::cout << name << "boom!!! Czesio is gone!" << std::endl;
}

void Zombie::setName(str name)
{
    this->name = name;
}

void Zombie::annouce()
{
    std::cout <<"Here comes " << this->name << "!" << std::endl;
}