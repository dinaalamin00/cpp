/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:09:02 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/18 17:11:58 by diahmed          ###   ########.fr       */
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
        Fixed(const Fixed& other);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed&   operator=(const Fixed& other);
        
        float toFloat( void ) const;
        int toInt( void ) const;
    };
    
std::ostream& operator<<(std::ostream &outputStream, const Fixed& FixedObj);

#endif
