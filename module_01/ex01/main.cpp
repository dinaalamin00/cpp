/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:47:02 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 09:47:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  stackZomb();
    Zombie  *heapZomb;
    
    heapZomb = newZombie("heap");
    heapZomb->announce();
    delete(heapZomb);

    randomChump("Stack");



    // z1 = newZombie("ZombieHeap")   // Allocated on heap
    // z1->announce()
    // delete z1   // Destructor is called

    // randomChump("ZombieStack")   // Created and destroyed automatically
}
