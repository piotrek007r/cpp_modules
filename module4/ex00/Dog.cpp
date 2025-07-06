#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    if(this != &other)
        this->type = other.type;    
    std::cout << "Dog copy assign operator called" << std::endl;
    return *this;
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woooof!" << std::endl;
}