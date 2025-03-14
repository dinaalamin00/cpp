/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:34 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 11:55:42 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  *heapZomb;
    
    heapZomb = newZombie("heap");
    heapZomb->announce();
    delete heapZomb;

    randomChump("Stack");

}
