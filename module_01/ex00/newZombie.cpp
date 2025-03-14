/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:40:08 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 11:53:16 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
    Zombie  *newZombie;

    newZombie = new Zombie(name);
	if (!newZombie)
	{
		std::cout << "Memory allocation failed" << std::endl;
	}
    return newZombie;
}
