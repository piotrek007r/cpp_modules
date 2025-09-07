#include "ScalarConvereter.hpp"

int main(int argc, char **argv)
{
        if(argc == 2)
        {
            // std::cout << "test!\n";
            ScalarConverter::convert(argv[1]);
        }
        return 1;
}
