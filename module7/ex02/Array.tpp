#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    arr = NULL;
}
template <typename T>
Array<T>::Array(unsigned int a) : arrLen(a)
{
    arr = new T[a](); // set all elemtnts of array to 0;
    std::cout << "new array was set" << std::endl;
}
template <typename T>
Array<T>::Array(const Array &other) : arrLen(other.arrLen)
{
    arr = new T[this->arrLen]();
    for(unsigned int i = 0; i < other.arrLen; i++)
        this->arr[i] = other.arr[i];
    std::cout << "copy constructor initialized" << std::endl;
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if(this != &other)
    {
        delete[] arr; 
        arrLen = other.arrLen;
        arr = new T[arrLen]();
        for(unsigned int i = 0; i < other.arrLen; i++)
            this->arr[i] = other.arr[i];
    }
    std::cout << "assigning operator initialized";
    return *this;
}
template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}
template <typename T>
int Array<T>::size() const
{
    std::cout << "size of array: " << this->arrLen << std::endl;
    return this->arrLen;
}
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= arrLen)
        throw std::out_of_range("out of range");
    return arr[index];
}