#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *newZombie[N];

    // newZombie = new Zombie[N];
    for (int i=0; i < N; i++)
        newZombie[i] =  new Zombie(name);

    return (newZombie);
}

       