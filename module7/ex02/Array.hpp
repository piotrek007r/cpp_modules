#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <time.h>


// template <typename T>
class Array
{
    private: 
        int *arr;
        unsigned int arrLen;

    public:
        Array();
        Array(unsigned int a);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        int size();
        int& operator[](unsigned int arrLen); 
};

#endif
