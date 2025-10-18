#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        RPN rpn;
        std::string input = argv[1];
        rpn.convertFromRPN(input);
    }
    else
        std::cout << "Error: invalid number of arguments" << std::endl;
}

/*
tests:
RPN: "2 3 +"
Infix: 2 + 3
Result: 5

RPN: "5 1 2 + 4 * + 3 -"
Infix: 5 + ((1 + 2) * 4) - 3
Result: 14

RPN: "4 13 5 / +"
Infix: 4 + (13 / 5)
Result: 6 

RPN: "2 3 4 * +"
Infix: 2 + (3 * 4)
Result: 14

RPN: "7 2 3 * -"
Infix: 7 - (2 * 3)
Result: 1

RPN: "1 + 2"
Infix: — (invalid)
Result: Error: malformed RPN (not enough operands)

RPN: "3 4 + +"
Infix: — (invalid)
Result: Error: malformed RPN (not enough operands)

RPN: "2 3 4 +"
Infix: — (invalid)
Result: Error: malformed RPN (extra operands left on stack)

RPN: "4 0 /"
Infix: 4 / 0
Result: Error: Are u nut? Don't try to divide by 0:)

RPN: "7"
Infix: — (invalid)
Result: Error: Malformed RPN (single token, no operator)
*/