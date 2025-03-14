#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0)
{
    std::cout<< "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& fixedObj)
{
    std::cout<< "Copy constructor called" <<std::endl;
    this->fixedPointValue = fixedObj.fixedPointValue;

}

Fixed::~Fixed()
{
    std::cout<< "Destructor called" <<std::endl;
}

Fixed&  Fixed::operator=(const Fixed& fixedObj)
{
    std::cout<< "Copy assignment operator called" <<std::endl;
    if (this != &fixedObj)
        this->fixedPointValue = (fixedObj.fixedPointValue);
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<< "getRawBits member function called" <<std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<< "getRawBits member function called" <<std::endl;
    this->fixedPointValue = raw;
}