#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType) {}

Weapon::~Weapon() {}

void    Weapon::setType(std::string newType)
{
    type = newType;
}

std::string const &Weapon::getType() const
{
    return (type);
}
