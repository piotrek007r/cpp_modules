#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << p.x + p.y;
    return os;
}

template<typename T1, typename T2, typename T3>
void iter(T1 *adress, const T2 len, T3 func)
{
    for(int i = 0; i < len; i++)
    {
        func(*adress);
        adress++;
    }
}
template<typename T1>
void foo(T1 const &arg)
{
    std::cout << arg << std::endl;
}

#endif