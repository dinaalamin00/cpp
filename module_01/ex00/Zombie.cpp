#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::~Zombie()
{
    std::cout<<name<<": destroyed"<<std::endl;
}

void    Zombie::announce() const
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}