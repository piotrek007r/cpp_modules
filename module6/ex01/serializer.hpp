#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data 
{
    uintptr_t adress;
};

class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

uintptr_t Serializer::serialize(Data *ptr)
{
    ptr->adress = reinterpret_cast<uintptr_t>(ptr);
    return ptr->adress;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

#endif