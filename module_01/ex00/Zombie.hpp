#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
        /* data */
    public:
        Zombie(std::string);
        ~Zombie();
        void announce() const;
};

Zombie* newZombie( std::string name);
void randomChump( std::string name );
#endif