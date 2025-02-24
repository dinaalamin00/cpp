/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:38:37 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 09:39:54 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::~Zombie()
{
    std::cout<<name<<": destroyed"<<std::endl;
}

void    Zombie::announce() const
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
