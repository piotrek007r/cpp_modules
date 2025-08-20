#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    const Bureaucrat *random = new Bureaucrat();
    Bureaucrat *domino = NULL;
    Intern *poorSod = new Intern();

    try
    {
        domino = new Bureaucrat("Domino", 5);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    AForm *presidentialPardonForm = poorSod->makeForm("presidental pardon", "Artur");
    AForm *shrubberyreationForm = poorSod->makeForm("robotomy request", "Artur");
    AForm *robotomyRequestForm = poorSod->makeForm("shrubbery creation", "Artur");

    domino->signForm(*presidentialPardonForm);
    domino->signForm(*shrubberyreationForm);
    domino->signForm(*robotomyRequestForm);

    std::cout << *presidentialPardonForm << std::endl;
    try
    {
        presidentialPardonForm->execute(*domino);
        shrubberyreationForm->execute(*domino);
        robotomyRequestForm->execute(*domino);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        domino->executeForm(*presidentialPardonForm);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    if(domino)
    {
        std::cout << *domino << std::endl;
        delete domino;
    }

    delete presidentialPardonForm;
    delete shrubberyreationForm;
    delete robotomyRequestForm;
    delete poorSod;
    delete random;

    return 0;
}