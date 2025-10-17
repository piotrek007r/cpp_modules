#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> stack;

    public:
       void convertFromRPN(char *rpn);
};

#endif