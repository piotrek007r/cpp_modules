#include "BitcoinExchange.hpp"

#include <iomanip>

// bool isDate(std::string date)
// {
//     size_t pos = date.find('-');
//     if(pos == std::string::npos)
//         return false;
//     int year = atoi((date.substr(0, pos).c_str())) ;
//     if(year < 2009 || year > 2022)
//         return false;
//     int month = atoi((date.substr(pos + 1, 2)).c_str());
//     if(month < 01 || month > 12)
//         return false;
//     pos = date.find('-', pos + 1);
//     if(pos == std::string::npos)
//         return false;
//     int day = atoi((date.substr(pos + 1, 2)).c_str());
//     if(day < 01 || day > 31)
//         return false;
//     return true;
// }

int main(int argc, char *argv[])
{   
    if(argc == 2)
        Bitcoin bitcoin(argv[1]);
    else
        std::cout << "Error: invalid parameter" << std::endl;
}

