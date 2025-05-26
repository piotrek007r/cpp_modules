#include <iostream>

typedef std::string string;

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOIS" << std::endl;
    else
    {
        for(int i = 1; i < argc; i++)
        {
            string str = argv[i];
            for (size_t j = 0; j < str.length(); ++j) {
                str[j] = std::toupper(str[j]);
            }
            std::cout << str << " ";
        }
    std::cout << std::endl;
    }
    return 0;
}
