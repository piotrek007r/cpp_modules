#include "repertory.hpp"

Fixed::Fixed()
{
    this->fixedNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedNum = other.fixedNum;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedNum = other.fixedNum;
    return *this;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedNum = num << this->fractNum;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedNum = roundf(num * (1 << fractNum));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->fixedNum) / (1 << fractNum);
}

int Fixed::toInt( void ) const
{
    return this->fixedNum >> this->fractNum;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}