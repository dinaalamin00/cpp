/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:52:46 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 12:52:48 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

	if (ac != 2)
	{
		std::cout<< "wrong num of arg" << std::endl;
		return 1;
	}

	harl.complain((std::string)av[1]);
    return 0;
}
