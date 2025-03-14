/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:26:19 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/14 12:24:36 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of arg"<<std::endl;
		return 1;
	}
	if (!argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cerr << "Error"<<std::endl;
		return 1;
	}
	sed	sed(argv[1], argv[2], argv[3]);
	if (!sed.process_file())
		return 1;
	std::cout<<"success"<<std::endl;

	return 0;
}
