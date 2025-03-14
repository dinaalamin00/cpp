/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:30:26 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 12:34:05 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nINFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nUnknown Level:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
