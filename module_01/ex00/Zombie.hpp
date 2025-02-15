#include<iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        void    announce(void);
        ~Zombie();
};