#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

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

Array::Array()
{
    arr = nullptr;
}

Array::Array(unsigned int a) : arrLen(a)
{
    arr = new int[a](); // set all elemtnts of array to 0;
}

Array::Array(const Array &other) : arrLen(other.arrLen)
{
    arr = new int[this->arrLen]();
    for(int i = 0; i < other.arrLen; i++)
        this->arr[i] = other.arr[i];
}

Array &Array::operator=(const Array &other)
{
    if(this != &other)
    {
        delete[] arr; 
        arrLen = other.arrLen;
        arr = new int[arrLen]();
        for(int i = 0; i < other.arrLen; i++)
            this->arr[i] = other.arr[i];
    }
    return *this;
}

Array::~Array()
{
    delete[] arr;
}

int Array::size()
{
    return this->arrLen;
}

int& Array::operator[](unsigned int index)
{
    if(index > arrLen)
        throw std::out_of_range("out of range");
    return arr[index];
}

#endif
