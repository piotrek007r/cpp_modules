#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        RPN rpn;
        rpn.convertFromRPN(argv[1]);
    }
    else
        std::cout << "Error: invalid number of parameters" << std::endl;
}