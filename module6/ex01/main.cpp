#include "serializer.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        Data *data;;

        Serializer::serialize(data);
        return 1;
    }
    else
        return 0;
}