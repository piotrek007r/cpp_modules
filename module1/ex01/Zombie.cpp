#include "repertory.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
    std::cout << name << "boom!!! Czesio is gone!" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::annouce()
{
    std::cout <<"Here comes " << this->name << "!" << std::endl;
}