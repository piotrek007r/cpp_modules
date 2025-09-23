#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <time.h>
#include <iostream>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base::~Base() {};

Base* generate(void)
{
    srand(time(NULL));

    Base base;
    Base *ptr = &base;
    int rndnum = rand();

    if((rndnum % 3) == 0)
    {
        Base *a = new A();
        return a; 
    }
    if((rndnum % 3) == 1)
    {
        Base *b = new B();
        return b; 
    }
    if((rndnum % 3) == 2)
    {
        Base *c = new C();
        return c; 
    }
    return ptr;
}

#endif