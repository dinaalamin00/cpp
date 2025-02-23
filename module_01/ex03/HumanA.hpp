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
        HumanA(std::string name, Weapon Weapon) : name(name), weaponA (Weapon){}
        ~HumanA();
        void    attack(){
            std::cout<<name<< "attacks with their" << weaponA.getType() <<std::endl;
        }
};



#endif
