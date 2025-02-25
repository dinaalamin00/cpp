#include "Zombie.hpp"


Zombie::Zombie(){}

Zombie::~Zombie()
{
    std::cout<<name<<": destroyed"<<std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce() const
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}