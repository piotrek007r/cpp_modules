#include "repertory.hpp"

Fixed::Fixed()
{
    this->fixedNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedNum = raw;
}

int Fixed::getRawBits( void )
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedNum;
}
