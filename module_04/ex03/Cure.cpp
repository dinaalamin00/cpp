#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other){}

Cure&   Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
Cure::~Cure() {}

// ------------ Clone & Use ------------------------------------
AMateria*    Cure::clone() const
{
   return new Cure(); 
}
void    Cure::use(ICharacter& target)
{
    std::cout<< "* heals " << target.getName() + "'s  wounds *\n";
}