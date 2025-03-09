/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:26:19 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/09 15:56:46 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		std::cerr << "sdfsdfsdfsdfdsfsd"<<std::endl;

	sed	sed(argv[1], argv[2], argv[3]);
	if (!sed.process_file())
		return 1;
	std::cout<<"success"<<std::endl;

	return 0;
}
