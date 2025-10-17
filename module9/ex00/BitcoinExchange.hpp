#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>

class Bitcoin
{
    private:
        std::map<std::string, double> btcChart;
        std::string path;

    public:
        Bitcoin();
        ~Bitcoin();
        Bitcoin(const Bitcoin& other);
        Bitcoin& operator=(const Bitcoin& other);
        Bitcoin(char *path);
        void setBtcChart();
        void compareDB(char *path);
        bool isDate(std::string date);
        bool isValue(float value);
        void findPairCalc(std::string date, float value);
};

#endif
