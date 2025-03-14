/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:05:20 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 12:13:33 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType) {}

Weapon::~Weapon() {}

void    Weapon::setType(std::string newType)
{
    type = newType;
}

std::string const &Weapon::getType()
{
    return (type);
}
