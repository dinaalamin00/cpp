#include "Weapon.hpp"

void    Weapon::setType(std::string newType)
{
    type = newType;
}

std::string*    const Weapon::getType()
{
    return (&type);
}
