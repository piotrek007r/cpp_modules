#include "ScalarConvereter.hpp"

bool ScalarConverter::isChar(std::string str)
{
    if(!str.empty() && (str.size() == 1))
        if(std::isprint(str[0]) && !isdigit(str[0]))
            return true;
    return false;
}

bool ScalarConverter::isInt(std::string str)
{
    if(str.empty())
        return false;
    if(str.size() == 1 && !std::isdigit(str[0]))
        return false;
    for(size_t i = 1; i < str.size(); i++)
        if(!std::isdigit(str[i]))
            return false;
    if(str[0] != '-' &&  str[0] != '+' && !std::isdigit(str[0]))
        return false; 
    return true;
}

bool ScalarConverter::isDouble(std::string str)
{
    bool hasDot = false;
    size_t i = 0;
    if(str == "-inf" || str == "+inf" || str == "nan")
        return true;
    if(str.empty() || str.size() < 2)
        return false;
    if(str[0] == '-' || str[0] == '+')
        i = 1;
    for(i = i; i < str.size(); i++)
    {
        if(str[i] == '.' && hasDot == true)
            return false;
        if(str[i] == '.')
            hasDot = true;
    }
    if(!hasDot)
        return false;
    for(i = 1; i < str.size(); i++)
        if(!std::isdigit(str[i]) && (str[i] != '.'))
            return false;
    if(str[0] != '-' &&  str[0] != '+' && str[0] != '.' && !std::isdigit(str[0]))
        return false; 
    return true;
}

bool ScalarConverter::isFloat(std::string str)
{
    bool hasDot = false;
    size_t i = 0;
    if(str.empty() || str.size() < 2 || (str[str.size() - 1] != 'f'))
        return false;
    if(str == "-inff" || str == "+inff")
        return true;
    if(str[0] == '-' || str[0] == '+')
        i = 1;
    for(i = i; i < str.size(); i++)
    {
        if(str[i] == '.' && hasDot == true)
            return false;
        if(str[i] == '.')
            hasDot = true;
    }
    if(!hasDot)
        return false;
    for(i = 1; i < str.size() -1; i++)
        if(!std::isdigit(str[i]) && (str[i] != '.'))
            return false;
    if(str[0] != '-' &&  str[0] != '+' && str[0] != '.' && !std::isdigit(str[0]))
        return false; 
    return true;
}

void ScalarConverter::convert(std::string str)
{
    std::string type;

    if(ScalarConverter::isChar(str))
    {
        std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" <<std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    }
    else if(ScalarConverter::isInt(str))
    {
        char *end;
        long val = strtol(str.c_str(), &end, 10);
        if(val > INT_MAX || val < INT_MIN)
        {
            std::cout << "char: " << "impossible" << std::endl; 
            std::cout << "int: " << "impossible" << std::endl; 
            std::cout << "float: " << "impossible" << std::endl; 
            std::cout << "double: " << "impossible" << std::endl;
            return;            
        }
        else if(val < 0 || val > 127)
            std::cout << "char: " << "impossible" << std::endl; 
        else if(!isprint(val))
            std::cout << "char: " << "Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(val)<< std::endl; 
        std::cout << "int: " << static_cast<int>(val) << std::endl;
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
    }
    else if(ScalarConverter::isDouble(str))
    {
        char *end;
        long double val = strtold(str.c_str(), &end);
        if(val > INT_MAX || val < INT_MIN)
        {
            std::cout << "char: " << "impossible" << std::endl; 
            std::cout << "int: " << "impossible" << std::endl; 
            std::cout << "float: " << "impossible" << std::endl; 
            std::cout << "double: " << "impossible" << std::endl;
            return;            
        }
        if(str == "-inf" || str == "+inf" || str == "nan")
        {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            if(str == "-inf")
            {
                std::cout << "float: " << "-inff" <<std::endl;
                std::cout << "double: " << "-inf" <<std::endl;
            }
            if(str == "+inf")
            {
                std::cout << "float: " << "+inff" <<std::endl;
                std::cout << "double: " << "+inf" <<std::endl;
            }
            if(str == "nan")
            {
                std::cout << "float: " << "nanf" <<std::endl;
                std::cout << "double: " << "nan" <<std::endl;
            }
        }
        else
        {
            if(atof(str.c_str()) < 0 || atof(str.c_str()) > 127)
                std::cout << "char: " << "impossible" << std::endl; 
            else if(!isprint(atof(str.c_str())))
                std::cout << "char: " << "Non displayable" << std::endl;
            else
                std::cout << "char: " << static_cast<char>(atof(str.c_str()))<< std::endl; 
            std::cout << "int: " << static_cast<int>(atof(str.c_str())) << std::endl;
            std::cout << "float: " << static_cast<float>(atof(str.c_str())) << ".0f" <<std::endl;
            std::cout << "double: " << static_cast<double>(atof(str.c_str())) << ".0" << std::endl;    
        }
    }
    else if(ScalarConverter::isFloat(str))
    {
        char *end;
        long double val = strtold(str.c_str(), &end);
        if(val > INT_MAX || val < INT_MIN)
        {
            std::cout << "char: " << "impossible" << std::endl; 
            std::cout << "int: " << "impossible" << std::endl; 
            std::cout << "float: " << "impossible" << std::endl; 
            std::cout << "double: " << "impossible" << std::endl;
            return;            
        }
        if(str == "-inff" || str == "+inff" || str == "nanf")
        {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            if(str == "-inff")
            {
                std::cout << "float: " << "-infff" <<std::endl;
                std::cout << "double: " << "-inff" <<std::endl;
            }
            if(str == "+inff")
            {
                std::cout << "float: " << "+infff" <<std::endl;
                std::cout << "double: " << "+inff" <<std::endl;
            }
            if(str == "nanf")
            {
                std::cout << "float: " << "nanff" <<std::endl;
                std::cout << "double: " << "nanf" <<std::endl;
            }
        }
        else
        {
            if(atof(str.c_str()) < 0 || atof(str.c_str()) > 127)
                std::cout << "char: " << "impossible" << std::endl; 
            else if(!isprint(atof(str.c_str())))
                std::cout << "char: " << "Non displayable" << std::endl;
            else
                std::cout << "char: " << static_cast<char>(atof(str.c_str()))<< std::endl; 
            std::cout << "int: " << static_cast<int>(atof(str.c_str())) << std::endl;
            std::cout << "float: " << static_cast<float>(atof(str.c_str())) << ".0f" <<std::endl;
            std::cout << "double: " << static_cast<double>(atof(str.c_str())) << ".0" << std::endl;    
        }
    }    
}