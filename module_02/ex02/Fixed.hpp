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
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed&   operator=(const Fixed& other);
        Fixed&   operator+(const Fixed& other);
        Fixed&   operator-(const Fixed& other);
        Fixed&   operator*(const Fixed& other);
        Fixed&   operator/(const Fixed& other);
        bool   operator>(const Fixed& other);
        bool   operator<(const Fixed& other);
        bool   operator>=(const Fixed& other);
        bool   operator<=(const Fixed& other);
        bool   operator==(const Fixed& other);
        bool   operator!=(const Fixed& other);

        Fixed& operator++(); 
        Fixed& operator++(); 
        Fixed& operator--(); 
        Fixed& operator--(); 
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat( void ) const;
        int toInt( void ) const;

};


#endif
