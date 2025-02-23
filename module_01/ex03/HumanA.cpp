#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), weaponA(Weapon){}

HumanA::~HumanA() {}
void    HumanA::attack() const
{
    std::cout<<name<< "attacks with their" << weaponA.getType() <<std::endl;
}