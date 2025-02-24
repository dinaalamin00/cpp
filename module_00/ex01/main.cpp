/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:00:40 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 12:33:09 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook   phonebook;
    std::string command;

    while(1)
    {
        std::cout<<"Enter a Command [ ADD | SEARCH | EXIT ]: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break ;
        if (command== "EXIT")
            break ;
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.displayAllContact();
        else
            std::cout<<"Invalid Command!\n";
    }
    return 0;
}
