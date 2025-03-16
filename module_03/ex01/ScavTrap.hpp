/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:22:21 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/16 11:27:20 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap();
		// ScavTrap(const std::string &name);
		// ScavTrap(const ClapTrap &other);
		// ScavTrap&	operator=(const ClapTrap &other);
		~ScavTrap();

		void guardGate();
};

// ScavTrap::ScavTrap(/* args */)
// {
// }

// ScavTrap::~ScavTrap()
// {
// }

#endif