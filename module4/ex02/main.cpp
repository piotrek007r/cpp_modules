#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main()
{

// AAnimal animal; // <- Uncomment this to prove that AAnimal cannot be instantiated

int numAnimals = 4;

AAnimal* animal[numAnimals];

for(int i = 0; i < numAnimals; i++)
{
    if(i % 2)
        animal[i] = new Cat();
    else
        animal[i] = new Dog();
}

int i = 2;
if(animal[i]->getType() == "Cat")
{
    Cat* cat = dynamic_cast<Cat*>(animal[i]);
    std::cout << cat->getType() << " " << cat->getBrain()->ideas[99] << std::endl;
}
else if(animal[i]->getType() == "Dog")
{
    Dog* dog = dynamic_cast<Dog*>(animal[i]);
    std::cout << dog->getType() << " " << dog->getBrain()->ideas[99] << std::endl;
}

for(int i = 0; i < numAnimals; i++)
    delete animal[i];

std::cout << "\n=== testing for brain deep copy ===\n" << std::endl;

Cat originalCat;
originalCat.getBrain()->ideas[0] = "I want to catch mice";

Cat copiedCat = originalCat;  // Uses copy constructor (deep copy)

copiedCat.getBrain()->ideas[0] = "I want to sleep";

std::cout << "Original Cat idea: " << originalCat.getBrain()->ideas[0] << std::endl;
std::cout << "Copied Cat idea: " << copiedCat.getBrain()->ideas[0] << std::endl;


return 0;
}
