/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:50:44 by diahmed           #+#    #+#             */
/*   Updated: 2025/02/24 11:53:37 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class   Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string newType);
        ~Weapon();
        std::string const &getType();
        void    setType(std::string newType);
};

#endif
