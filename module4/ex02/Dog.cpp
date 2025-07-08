#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
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
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woooof!" << std::endl;
}

Brain* Dog::getBrain()
{
    return this->brain;
}