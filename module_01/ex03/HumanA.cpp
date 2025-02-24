/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:59:45 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 12:10:55 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), weaponA(Weapon){}

HumanA::~HumanA() {}

void    HumanA::attack() const
{
    std::cout<<name<< " attacks with their " << weaponA.getType() <<std::endl;
}
