#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename X>
X min(X a, X b)
{
    return a < b ? a : b;
}

template <typename Y>
Y max(Y a, Y b)
{
    return a > b ? a : b;
}

#endif