#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon  &weaponA;
        /* data */
    public:
        HumanA(std::string name, Weapon &Weapon);
        ~HumanA();
        void    attack() const;
};


#endif
