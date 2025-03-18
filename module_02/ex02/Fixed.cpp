/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:15:03 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/18 18:20:20 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0) {}

Fixed::Fixed(const int num) // int to fixed point
{
    fixedPointValue = num << fractionalBits;
}

Fixed::Fixed(const float num) // float to fixed point
{
    fixedPointValue =  roundf(num * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other ;
}

Fixed::~Fixed() {}

Fixed&  Fixed::operator=(const Fixed& other)
{
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

std::ostream& operator<<(std::ostream &outputStream, const Fixed& FixedObj)
{
    outputStream << FixedObj.toFloat();
    return outputStream;
}

/* --------------------------------------------------------------------------------------- */

Fixed&  Fixed::operator+(const Fixed& other)
{
    this->fixedPointValue = this->fixedPointValue + other.fixedPointValue;
    return *this;
}

Fixed&  Fixed::operator-(const Fixed& other)
{
    this->fixedPointValue = this->fixedPointValue - other.fixedPointValue;
    return *this;
}

Fixed  Fixed::operator*(const Fixed& other)
{
    Fixed result(this->toFloat() * other.toFloat());
    return result;
}

Fixed  Fixed::operator/(const Fixed& other)
{
	Fixed result(this->toFloat() / other.toFloat());
    return result;
}

bool  Fixed::operator>(const Fixed& other) const
{
    return this->fixedPointValue > other.fixedPointValue;
}

bool  Fixed::operator<(const Fixed& other) const
{
    return this->fixedPointValue < other.fixedPointValue;
}

bool  Fixed::operator>=(const Fixed& other) const
{
    return this->fixedPointValue >= other.fixedPointValue;

}

bool  Fixed::operator<=(const Fixed& other) const
{
    return this->fixedPointValue <= other.fixedPointValue;
}

bool  Fixed::operator==(const Fixed& other) const
{
    return this->fixedPointValue == other.fixedPointValue;
}

bool  Fixed::operator!=(const Fixed& other) const
{
    return this->fixedPointValue != other.fixedPointValue;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}

Fixed& Fixed::operator++()
{
    ++this->fixedPointValue;
    return *this;

}

Fixed Fixed::operator++(int)
{
    Fixed   temp(*this);

    ++this->fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--()
{
    --this->fixedPointValue;
    return *this;
} 
Fixed Fixed::operator--(int)
{
    Fixed   temp(*this);

    --this->fixedPointValue;
    return temp;
}
