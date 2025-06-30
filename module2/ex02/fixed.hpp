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

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int fixedNum;
        static const int fractNum = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif