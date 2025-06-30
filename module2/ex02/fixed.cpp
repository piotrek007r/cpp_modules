#include "repertory.hpp"

Fixed::Fixed()
{
	this->fixedNum = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->fixedNum = other.fixedNum;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedNum = other.fixedNum;
	return (*this);
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixedNum = num << this->fractNum;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixedNum = roundf(num * (1 << fractNum));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedNum) / (1 << fractNum));
}

int Fixed::toInt(void) const
{
	return (this->fixedNum >> this->fractNum);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedNum > other.fixedNum)
		return (true);
	else
		return (false);
}
bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedNum < other.fixedNum)
		return (true);
	else
		return (false);
}
bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedNum >= other.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedNum <= other.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedNum == other.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedNum != other.fixedNum)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->fixedNum + other.fixedNum);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->fixedNum - other.fixedNum);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->fixedNum / other.fixedNum);
}

Fixed& Fixed::operator++()
{
	this->fixedNum = this->fixedNum + 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed current = *this;
	++this->fixedNum;
	return current;
}

Fixed& Fixed::operator--()
{
	this->fixedNum = this->fixedNum - 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed current = *this;
	--this->fixedNum;
	return current;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{	
	if(a < b)
		return a;
	else 
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{	
	if(a < b)
		return a;
	else 
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{	
	if(a > b)
		return a;
	else 
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{	
	if(a > b)
		return a;
	else 
		return b;
}


