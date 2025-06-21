#include "repertory.hpp"

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed&);
        ~Fixed();


        void setRawBits( int const raw );
        int getRawBits( void );
    private:
        int fixedNum;
        static const int fractNum = 8;
};

//Fixed::Fixed()
//{
//    this->fixedNum = 0;
//    std::cout << "Default constructor called" << std::endl;
//}

//Fixed::Fixed(const Fixed&)
//{
//    std::cout << "Copy constructor called" << std::endl;
//}

//Fixed::~Fixed()
//{
//    std::cout << "Destructor called" << std::endl;
//}

//void Fixed::setRawBits(int const raw)
//{
//    this->fixedNum = raw;
//}

//int Fixed::getRawBits( void )
//{
//    std::cout << "getRawBits member function called" << std::endl;
//    return this->fixedNum;
//}

//int main( void )
//{
//Fixed a;
//Fixed b( a );
//Fixed c;

//c = b;

//std::cout << a.getRawBits() << std::endl;
//std::cout << b.getRawBits() << std::endl;
//std::cout << c.getRawBits() << std::endl;
//return 0;
//}
