#include "repertory.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout <<
        "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout <<
         "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout <<
         "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
        << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout <<
          "This is unacceptable! I want to speak to the manager now."
        << std::endl << std::endl;

}

void Harl::complain( std::string level )
{
    std::string levelsArr[] = {"debug", "info", "warning", "error"};
    size_t i;

    for(i = 0; i < 4; i++)
    {
        if(levelsArr[i] == level)
            break;
    }
    switch (i)
    {
        case 0:
            this->debug();
            /* fall through */
        case 1:
            this->info();
            /* fall through */
        case 2:
            this->warning();
            /* fall through */
        case 3:
            this->error();
        break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
