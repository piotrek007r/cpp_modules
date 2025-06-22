#include "repertory.hpp"

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();


        void setRawBits( int const raw );
        int getRawBits( void ) const;
    private:
        int fixedNum;
        static const int fractNum = 8;
};

