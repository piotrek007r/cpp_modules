#include "repertory.hpp"

int main()
{
    std::string level;
    Harl Harl;

    while(true)
    {
        std::cout << std::endl;
        std::cout << "please type a comlain level: debug, info, warning, error, exit" << std::endl;
        std::cout << std::endl;
        std::getline(std::cin, level);
        if(level == "debug")
            Harl.complain("debug");
        else if(level == "info")
            Harl.complain("info");
        else if(level == "warning")
            Harl.complain("warning");
        else if(level == "error")
            Harl.complain("error");
        else if(level == "exit")
            break;
        else
            std::cout << "wrong level type, TRY AGAIN!" << std::endl;

    }
}