#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    if(this != &other)
        this->type = other.type;    
    std::cout << "Cat copy assign operator called" << std::endl;
    return *this;
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "meeeeow!" << std::endl;
}

Brain* Cat::getBrain()
{
    return this->brain;
}




