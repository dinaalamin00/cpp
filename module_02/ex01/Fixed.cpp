/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:38 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/18 17:11:43 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0)
{
    std::cout<< "Default constructor called" <<std::endl;
}

Fixed::Fixed(const int num) // int to fixed point
{
    std::cout<< "Int constructor called" <<std::endl;
    fixedPointValue = num << fractionalBits;
}

Fixed::Fixed(const float num) // float to fixed point
{
    std::cout<< "Float constructor called" <<std::endl;
    fixedPointValue =  roundf(num * (1 << fractionalBits));
}


int Fixed::toInt( void ) const // fixed point to int
{
    return (this->fixedPointValue >> fractionalBits);
}

float Fixed::toFloat( void ) const // fixed point to float
{
    return static_cast <float> (this->fixedPointValue) / (1 << fractionalBits);
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    std::cout<< "Copy assignment operator called" <<std::endl;
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
    return *this;
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


std::ostream& operator<<(std::ostream &outputStream, const Fixed& FixedObj)
{
    outputStream << FixedObj.toFloat();
    return outputStream;
}
