/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:47:02 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 11:59:45 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  *Zomb;
    int     n;

    n = 3;
    Zomb = zombieHorde(n, "Bob");
    for (int i=0; i<n; i++)
        Zomb[i].announce();
   
    delete[] Zomb;
    return 0;

}
