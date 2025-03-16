#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed&   operator=(const Fixed& other);
        
        float toFloat( void ) const;
        int toInt( void ) const;
        // int getRawBits(void) const;
        // void setRawBits(int const raw);
    };
    
std::ostream& operator<<(std::ostream &outputStream, const Fixed& FixedObj);

#endif
