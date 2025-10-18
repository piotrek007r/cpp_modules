#include "RPN.hpp"

void RPN::convertFromRPN(std::string rpn)
{   
    std::istringstream iss(rpn);
    std::string tok;
    int counter = 0;
    int result;
    int checkInt;

    while (iss >> tok)
    {
        std::istringstream tokBuff(tok);
        if(tokBuff >> checkInt)
        {
            if(checkInt >= 10)
                error(1);
            this->stack.push(checkInt);
        }
        else
        {   
            if(stack.size() < 2)
                error(2);
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            result = calc(left, right, tok);
            stack.push(result);
        }
        counter++;
    }

    if(!(stack.size() == 1) || (counter == 1))
        error(2);
    std::cout << "final result: " << result << std::endl;
}

void RPN::error(int i)
{
    if(i == 1)
        std::cerr << "Error: Number argument bigger than 9" << std::endl;
    if(i == 2)
        std::cerr << "Error: Malformed RPN" << std::endl;
    if(i == 3)
        std::cerr << "Error: Are u nut? Don't try to divide by 0:)" << std::endl;
    exit(1);
}

int RPN::calc(int left, int right, std::string tok)
{
    if(tok == "+")
        return left + right; 
    if(tok == "-")
        return left - right;
    if(tok == "*")
        return left * right; 
    if(tok == "/")
    {
        if(right == 0)
            error(3);
        else
            return left / right;
    }   
    return 1;
}
