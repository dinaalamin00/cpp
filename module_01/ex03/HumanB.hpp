#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon  *weaponB;
        /* data */
    public:
        HumanB(std::string name);
        ~HumanB();
        void    setWeapon(Weapon &Weapon);
        void    attack() const;
};


#endif
