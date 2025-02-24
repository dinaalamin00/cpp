/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:59:05 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/15 21:59:12 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "contact.hpp"
#include	<stdlib.h>

class   PhoneBook
{
    private:
        Contact contact[8];
        int     contactCount;
        int     oldestIndex;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact() const;
        void    displayAllContact() const;
};

void    check_empty_input(std::string input, std::string title);

#endif