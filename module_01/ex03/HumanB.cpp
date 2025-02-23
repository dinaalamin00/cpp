#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name), weaponB(NULL) {}
HumanB::~HumanB() {}
void    HumanB::setWeapon(Weapon &Weapon)
{
    HumanB::weaponB = &Weapon;
}

void    HumanB::attack() const
{
    if (weaponB)
        std::cout<<name<< "attacks with their" << weaponB->getType() <<std::endl;
    else
        std::cout << name<< " has no weapon to attack with!" << std::endl;
}