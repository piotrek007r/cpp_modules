#include "Animal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() 
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    this->type = other.type;
}

AAnimal &AAnimal::operator=(const AAnimal& other)
{
    if(this != &other)
        this->type = other.type;    
    std::cout << "AAnimal copy assign operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "Unknown animal make a sound" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}
