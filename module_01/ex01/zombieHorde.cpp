/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:47:48 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 09:50:04 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *newZombie = new Zombie[N];

    for (int i=0; i < N; i++)
        newZombie[i].setName(name);
    return (newZombie);
}
