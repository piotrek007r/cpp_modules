#include "Serializer.hpp"

int main()
{
        Data str;
        Data *data = &str;
        Data *newptr = NULL;
        uintptr_t adr = 0;

        adr = Serializer::serialize(data);
        std::cout << data << std::endl;
        std::cout << adr << std::endl;
        newptr = Serializer::deserialize(adr);
        std::cout << newptr << std::endl;
        return 1;
}