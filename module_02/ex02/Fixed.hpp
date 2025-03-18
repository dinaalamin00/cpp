/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:13:35 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/18 18:20:32 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed&   operator=(const Fixed& other);
        Fixed&   operator+(const Fixed& other);
        Fixed&   operator-(const Fixed& other);
        Fixed   operator*(const Fixed& other);
        Fixed   operator/(const Fixed& other);
        bool   operator>(const Fixed& other) const;
        bool   operator<(const Fixed& other) const;
        bool   operator>=(const Fixed& other) const;
        bool   operator<=(const Fixed& other) const;
        bool   operator==(const Fixed& other) const;
        bool   operator!=(const Fixed& other) const;

        Fixed& operator++(); 
        Fixed operator++(int); 
        Fixed& operator--(); 
        Fixed operator--(int); 
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<(std::ostream &outputStream, const Fixed& FixedObj);


#endif
