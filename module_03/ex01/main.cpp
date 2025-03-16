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

int main(){

    // ClapTrap robot;
    // ClapTrap robot("Clappy");
    
    // robot.attack("Enemy1");
    // robot.takeDamage(5);
    // robot.beRepaired(3);

	ClapTrap robot("RoboWarrior");

	robot.attack("EnemyBot"); // Uses 1 energy
	robot.takeDamage(5);      // Reduces HP
	robot.beRepaired(3);      // Uses 1 energy, restores HP
	robot.takeDamage(15);     // Drops HP to 0 (defeated)
	robot.attack("AnotherBot"); // Cannot attack due to 0 HP
	robot.beRepaired(5); // Cannot repair due to 0 HP

    
    return 0;
}
