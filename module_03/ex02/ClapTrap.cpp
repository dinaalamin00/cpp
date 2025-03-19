/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:46:51 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/16 11:25:18 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<< "ClapTrap Constructor" <<std::endl;
}

ClapTrap::ClapTrap(const std::string &_name): name(_name),  hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<< "ClapTrap "<<name<< " created!" <<std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << other.name << " has been assigned!" << std::endl;
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout<< "ClapTrap Destructor" <<std::endl;
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

//Reduces the target's hit points by attackDamage.
//Costs 1 energy point.

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout<< "ClapTrap " <<name<<  " can't attack!" <<std::endl;
		return ;
	}
	std::cout<< "ClapTrap " <<name<< " attacks " <<target<< ", causing " <<attackDamage<< " points of damage!";
	std::cout<< std::endl;
	energyPoints = energyPoints - 1;
}

//Reduces ClapTrap’s hit points by amount.
//If hit points reach 0, ClapTrap is considered defeated.

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = hitPoints - amount;
	std::cout<< "ClapTrap " <<name<< " takes " <<amount<< " damage! Remaining Hit Points: " <<hitPoints;
	std::cout << std::endl;
}

//Restores hit points by amount.
//Costs 1 energy point.

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout<< "ClapTrap " <<name<<  " can't repair!" <<std::endl;
		return ;
	}
	hitPoints = hitPoints + amount;
	energyPoints = energyPoints - 1;
	std::cout<< "ClapTrap " <<name<< " repairs itself, recovering " <<amount<< " Hit Points!";
	std::cout << std::endl;

}
