#include <iostream>


void toUpper(char **str)
{
    int i = 1;

    while(str[i])
    {
        int j = 0;
        while(str[i][j])
        {
            if(str[i][j] <= 'z' && str[i][j] >= 'a')
                str[i][j] = str[i][j] - 32;
            j++;
        }
        std::cout << str[i] << " ";
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOIS" << std::endl;
    else
    {
        toUpper(argv);
        std::cout << std::endl;
    }
}