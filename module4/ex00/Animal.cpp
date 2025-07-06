#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() 
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    this->type = other.type;
}

Animal &Animal::operator=(const Animal& other)
{
    if(this != &other)
        this->type = other.type;    
    std::cout << "Animal copy assign operator called" << std::endl;
    return *this;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Unknown animal make a sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
