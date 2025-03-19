/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:27:36 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/16 11:29:44 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout<< "ScavTrap Constructor" <<std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout<< "ScavTrap "<<_name<< " created!" <<std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    if (this != &other)
       ClapTrap::operator=(other);
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout<< "ScavTrap Copy Constructor called" <<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<< "ScavTrap Destructor" <<std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout<< "ScavTrap " <<name<<  " can't attack!" <<std::endl;
		return ;
	}
	std::cout<< "ScavTrap " <<name<< " attacks " <<target<< ", causing " <<attackDamage<< " points of damage!";
	std::cout<< std::endl;
	energyPoints = energyPoints - 1;

}

void ScavTrap::guardGate()
{
	std::cout<< "ScavTrap " <<name<< " is now in Gate keeper mode." <<std::endl;
}
