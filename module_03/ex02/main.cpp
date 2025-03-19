/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:15:47 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/16 10:55:09 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Guardian");

    scav.attack("EnemyBot");   // Uses 1 energy
    scav.takeDamage(30);       // Reduces HP
    scav.beRepaired(20);       // Uses 1 energy, restores HP
    scav.guardGate();          // Special ability
    scav.takeDamage(100);      // Drops HP to 0 (defeated)
    scav.attack("AnotherBot"); // Cannot attack due to 0 HP
    scav.beRepaired(5);        // Cannot repair due to 0 HP

    return 0;
}
