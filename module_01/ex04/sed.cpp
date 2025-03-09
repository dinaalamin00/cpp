/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:36:52 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/09 15:58:12 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

sed::sed(std::string file, std::string str1, std::string str2): filename(file), s1(str1), s2(str2){}

sed::~sed(){}

bool	sed::process_file()
{
	std::ifstream	infile(filename);
	if (!infile)
	{
		std::cerr << "Error: Cannot open the file!" << std::endl;
		return false;
	}
	std::string	outfile = filename + ".replace";
	std::ofstream	ofile(outfile);
	if (!ofile)
	{
		std::cerr << "Error: Cannot open the outfile!" << std::endl;
		return false;
	}
	std::string	line;
	while(std::getline(infile, line))
	{
		size_t	i = 0;

		i = line.find(s1, i);
		while (i != std::string::npos)
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
			i += s2.length();
			i = line.find(s1, i);
		}
		ofile<<line<<std::endl;
	}
	
	infile.close(); 
	ofile.close(); 
	return true;
}
