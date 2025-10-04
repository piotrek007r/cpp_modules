#include "Base.hpp"

Base::~Base() {};

Base* generate(void)
{
    Base base;
    Base *ptr = &base;
    int rndnum = rand();

    if((rndnum % 3) == 0)
        return new A();
    if((rndnum % 3) == 1)
        return new B();
    if((rndnum % 3) == 2)
        return new C();
    return ptr;
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A was created(pointer)" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B was created(pointer)" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C was created(pointer)" << std::endl;
}

void identify(Base& p)
{
    Base dummy;
    try
    {
        dummy = dynamic_cast<A&>(p);
        std::cout << "A was created(reference)" << std::endl;
        return;
    } catch(...) {}
    try
    {
        dummy = dynamic_cast<B&>(p);
        std::cout << "B was created(reference)" << std::endl;
        return;
    } catch(...) {}
    try
    {
        dummy = dynamic_cast<C&>(p);
        std::cout << "C was created(reference)" << std::endl;
        return;
    } catch(...) {}
}
