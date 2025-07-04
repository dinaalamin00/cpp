#include "Ice.hpp"


Ice::Ice() : AMateria("ice")
{
    std::cout<< "Ice Constructor\n";

}

Ice::Ice(const Ice& other) : AMateria(other){}
Ice&   Ice::operator=(const Ice& other)
{
    if (this!= &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Ice::~Ice()
{

}

AMateria*    Ice::clone() const
{
    return new Ice();
}

void    Ice::use(ICharacter& target) 
{
    std::cout<< "* shoots an ice bolt at " << target.getName() + " *\n";
}