#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory addres of a string: "<< &str << std::endl;
    std::cout << "Memory addres held by stringPTR: "<< stringPTR << std::endl;
    std::cout << "Memory addres held by stringREF: "<< &stringREF << std::endl;

    std::cout << "Value of a string: " << str << std::endl;
    std::cout << "Value of a stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of a stringREF: " << stringREF << std::endl;

    return 0;
}