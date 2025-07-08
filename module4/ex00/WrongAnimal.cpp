#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
        this->type = other.type;    
    std::cout << "WrongAnimal copy assign operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Unknown animal make a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
