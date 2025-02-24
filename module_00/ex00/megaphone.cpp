/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:53:43 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 12:24:23 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(i = 1; (int)i < argc; i++)
	{
		for (j = 0; j < strlen(argv[i]); j++)
        	argv[i][j] = toupper(argv[i][j]);
		
	}
	i = 1;
	for (int i = 1; (int)i < argc; i++)
		std::cout<<argv[i];
	std::cout<<std::endl;
	return (0);	
}
