#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>


class   Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string newType) : type(newType) {}
        std::string* const getType();
        void    setType(std::string newType);
};
#endif