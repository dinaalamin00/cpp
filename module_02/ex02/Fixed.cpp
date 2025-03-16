#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0)
{
    std::cout<< "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<< "Copy constructor called" <<std::endl;
    *this = other ;
}

Fixed::~Fixed()
{
    std::cout<< "Destructor called" <<std::endl;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout<< "Copy assignment operator called" <<std::endl;
    if (this != &other)
    this->fixedPointValue = other.fixedPointValue;
    return *this;
}
int Fixed::toInt( void ) const // fixed point to int
{
    return (this->fixedPointValue >> fractionalBits);
}

float Fixed::toFloat( void ) const // fixed point to float
{
    return static_cast <float> (this->fixedPointValue) / (1 << fractionalBits);
}

/* --------------------------------------------------------------------------------------- */

Fixed&  Fixed::operator+(const Fixed& other)
{
    if (this != &other)
    this->fixedPointValue = this->fixedPointValue + other.fixedPointValue;
    return *this;
}

Fixed&  Fixed::operator-(const Fixed& other)
{
    if (this != &other)
    this->fixedPointValue = this->fixedPointValue - other.fixedPointValue;
    return *this;
}

Fixed&  Fixed::operator*(const Fixed& other)
{
    if (this != &other)
        this->fixedPointValue = this->fixedPointValue * other.fixedPointValue;
    return *this;
}

Fixed&  Fixed::operator/(const Fixed& other)
{
    if (this != &other)
        this->fixedPointValue = this->fixedPointValue / other.fixedPointValue;
    return *this;
}

bool  Fixed::operator>(const Fixed& other)
{
    return this->fixedPointValue > other.fixedPointValue;
}

bool  Fixed::operator<(const Fixed& other)
{
    return this->fixedPointValue < other.fixedPointValue;
}

bool  Fixed::operator>=(const Fixed& other)
{
    return this->fixedPointValue >= other.fixedPointValue;

}

bool  Fixed::operator<=(const Fixed& other)
{
    return this->fixedPointValue <= other.fixedPointValue;
}

bool  Fixed::operator==(const Fixed& other)
{
    return this->fixedPointValue == other.fixedPointValue;
}

bool  Fixed::operator!=(const Fixed& other)
{
    return this->fixedPointValue != other.fixedPointValue;
}


Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
