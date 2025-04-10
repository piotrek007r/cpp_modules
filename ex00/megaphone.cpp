#include <iostream>

using namespace std;

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
        cout << str[i] << " ";
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 1)
        cout << "LOUD AND UNBEARABLE FEEDBACK NOIS" << endl;
    else
    {
        toUpper(argv);
        cout << endl;
    }
}