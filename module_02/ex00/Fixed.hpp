#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixedObj);
        ~Fixed();
        Fixed&   operator=(const Fixed& fixedObj);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};



#endif
