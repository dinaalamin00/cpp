/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:25:17 by diahmed           #+#    #+#             */
/*   Updated: 2025/03/09 15:10:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class sed
{
	private:
		std::string	filename;
		std::string	s1;
		std::string	s2;
	public:
		sed(std::string file, std::string str1, std::string str2);
		~sed();
		bool	process_file();
	// private:
	// 	std::string	replace_content(std::string file);
};

#endif