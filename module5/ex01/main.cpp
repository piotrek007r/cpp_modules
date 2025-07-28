#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    const Bureaucrat *random = new Bureaucrat();
    const Bureaucrat *domino = NULL;
    Form *blank = new Form();
    Form *visa = new Form("visa", 10, 50);

    try
    {
        domino = new Bureaucrat("Domino", 9);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    domino->signForm(*visa);
    std::cout << *visa << std::endl;

    if(domino)
    {
        std::cout << *domino << std::endl;
        delete domino;
    }

    delete random;
    delete blank;
    delete visa;

    return 0;
}