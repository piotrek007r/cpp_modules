#ifndef SCALARCONVERETER_HPP
#define SCALARCONVERETER_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        static void convert(std::string str);
        static bool isChar(std::string str);
        static bool isInt(std::string str);
        static bool isDouble(std::string str);
        static bool isFloat(std::string str);
};

#endif

