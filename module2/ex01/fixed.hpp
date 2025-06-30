#ifndef FIXED_HPP
#define FIXED_HPP

#include "repertory.hpp"

class Fixed
{
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed& operator=(const Fixed& other);
        Fixed(const Fixed& other);
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int fixedNum;
        static const int fractNum = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif