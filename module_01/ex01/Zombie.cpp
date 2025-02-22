#include "Zombie.hpp"


Zombie::~Zombie()
{
    std::cout<<name<<": destroyed"<<std::endl;
}

void    Zombie::announce() const
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}