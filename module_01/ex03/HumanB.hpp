#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon  &weaponB;
        /* data */
    public:
        HumanB(std::string name, Weapon Weapon):name(name), weaponB(null) {}
        ~HumanB();
        void    setWeapn(Weapon Weapon);
        void    attack(){
            std::cout<<name<< "attacks with their" << weaponB.getType() <<std::endl;
        }
};


#endif
