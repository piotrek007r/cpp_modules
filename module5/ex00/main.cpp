#include "Bureaucrat.hpp"

int main()
{
    const Bureaucrat *random = new Bureaucrat();
    const Bureaucrat *domino = NULL;
    Bureaucrat *krzysiek = NULL;
    Bureaucrat *bastian = NULL;

    try
    {
        domino = new Bureaucrat("Domino", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        krzysiek = new Bureaucrat("Krzysiek", 1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    if(krzysiek)
    {
        try
        {
            krzysiek->incraseGrade();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << *krzysiek << std::endl;
        delete krzysiek;
    }
    if(domino)
    {
        std::cout << *domino << std::endl;
        delete domino;
    }

    delete random;
    delete bastian;

    return 0;
}