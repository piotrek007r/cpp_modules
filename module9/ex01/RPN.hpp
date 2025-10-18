#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdlib.h>


class RPN
{
    private:
        std::stack<int> stack;

    public:
       void convertFromRPN(std::string rpn);
       int calc(int left, int right, std::string tok);
       void error(int i);
};

#endif