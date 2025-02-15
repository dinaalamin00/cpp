#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){}

Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie  new *newZom;

    newZom->name = name;
    return (newZom);

}