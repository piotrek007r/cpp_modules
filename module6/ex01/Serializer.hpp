#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "data.hpp"

class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif