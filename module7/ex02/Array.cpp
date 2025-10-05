#include "Array.hpp"

Array::Array()
{
    arr = NULL;
}

Array::Array(unsigned int a) : arrLen(a)
{
    arr = new int[a](); // set all elemtnts of array to 0;
}

Array::Array(const Array &other) : arrLen(other.arrLen)
{
    arr = new int[this->arrLen]();
    for(unsigned int i = 0; i < other.arrLen; i++)
        this->arr[i] = other.arr[i];
}

Array &Array::operator=(const Array &other)
{
    if(this != &other)
    {
        delete[] arr; 
        arrLen = other.arrLen;
        arr = new int[arrLen]();
        for(unsigned int i = 0; i < other.arrLen; i++)
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
    std::cout << "size of array: " << this->arrLen << std::endl;
    return this->arrLen;
}

int& Array::operator[](unsigned int index)
{
    if(index >= arrLen)
        throw std::out_of_range("out of range");
    return arr[index];
}