#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"
#include <iostream>
#include <string>

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << i->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete j;
delete i;
delete meta;

std::cout << "\n=== wrongAnimals test ===\n" << std::endl; 
const WrongAnimal* wrong = new WrongCat();
wrong->makeSound();

delete wrong;

return 0;
}
