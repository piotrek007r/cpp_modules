#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(char *path)
{
    this->setBtcChart();
    this->compareDB(path);
}

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin& other) : btcChart(other.btcChart), path(other.path) {}

Bitcoin& Bitcoin::operator=(const Bitcoin& other)
{
    if(this != &other)
    {
        this->path = other.path;
        this->btcChart = other.btcChart;
    }
    return *this;    
}

void Bitcoin::setBtcChart()
{
    std::string line;
    std::ifstream inFileDB("data.csv");
    if(!inFileDB)
    {
        std::cout << "Error: couldn't open data.csv" << std::endl;
        exit(1);
    }

    while(std::getline(inFileDB, line))
    {
        size_t pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string exchange_rateStr = line.substr(pos + 1, (line.size() - pos));
        // used atof becouse data from DB is safe and guarantee float in second param
        double exchange_rate = atof(exchange_rateStr.c_str());
        btcChart.insert(std::make_pair(date, exchange_rate));
    }
}

void Bitcoin::findPairCalc(std::string date, float value)
{
    std::map<std::string, double>::iterator pair =  btcChart.lower_bound(date);
    if(pair == btcChart.end() && (pair != btcChart.begin()))
        pair--;
    else if((pair != btcChart.begin() ) && (pair->first != date))
        pair--;
    std::cout << pair->first << " => " << value << " = " << pair->second * value << std:: endl;
}

void Bitcoin::compareDB(char *path)
{
    std::string line;
    std::ifstream inFileIndex(path);
    if(!inFileIndex)
    {
        std::cout << "Error: couldn't open input file" << std::endl;
        exit(1);
    }
    std::getline(inFileIndex, line); // skip first line
    while(std::getline(inFileIndex, line))
    {
        size_t pos = line.find('|');
        if(pos == std::string::npos)
        {
            std::cout << "Error: Invalid line format => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        if(!isDate(date))
        {
            std::cout << "Error: Invalid date => " << date << std::endl;
            continue;
        }
        std::string valueStr = line.substr(pos + 1, (line.size() - pos));
        float value = atof(valueStr.c_str());
        if(!isValue(value))
            continue;
        findPairCalc(date, value);
    }
}

bool Bitcoin::isDate(std::string date)
{
    size_t pos = date.find('-');
    if(pos == std::string::npos)
        return false;
    int year = atoi((date.substr(0, pos).c_str())) ;
    if(year < 2009 || year > 2022)
        return false;
    int month = atoi((date.substr(pos + 1, 2)).c_str());
    if(month < 01 || month > 12)
        return false;
    pos = date.find('-', pos + 1);
    if(pos == std::string::npos)
        return false;
    int day = atoi((date.substr(pos + 1, 2)).c_str());
    if(day < 01 || day > 31)
        return false;
    return true; 
}

bool Bitcoin::isValue(float value)
{
    if(value < 0)
    {
        std::cout << "Error: not a positive number => " << value << std::endl;
        return false;
    }
    if(value > 1000)
    {
        std::cout << "Error: value too large => " << value << std::endl;
        return false;
    }
    return true;
}