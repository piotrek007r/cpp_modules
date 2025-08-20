#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}
Intern::Intern(const Intern &other)
{
    std::cout << "copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    if(this != &other)
        (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string formsArr[] = {"PresidentialPardonForm", 
        "presidental pardon", 
        "RobotomyRequestForm", 
        "robotomy request",
        "ShrubberyCreationForm",
        "shrubbery creation"};
    
    int i;
    for(i = 0; i < 6; i++)
    {
        if(formsArr[i] == name)
            break;
    }

    switch(i)
    {
        case 0:
        case 1:
            std::cout << "Intern create PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
        case 2:
        case 3:
            std::cout << "Intern create RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case 4:
        case 5:
            std::cout << "Intern create ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(target);
        default:
            std::cout << "this form doesnt exist! try again" << std::endl;
    }

    return NULL;
}