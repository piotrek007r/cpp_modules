#include "repertory.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        std::string level = argv[1];
        Harl Harl;
        std::transform(level.begin(), level.end(), level.begin(), ::tolower);
        Harl.complain(level);
    }
    else
    {
        std::cout << "invalid number of parameters" << std::endl;
        return 0;
    }
}


