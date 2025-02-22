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
    Zombie(std::string zombieName) : name(zombieName) {}
    ~Zombie();
        void announce() const;
};

Zombie* zombieHorde( int N, std::string name );

#endif