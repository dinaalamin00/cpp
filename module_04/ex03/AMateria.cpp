#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
    std::cout<< "AMateria Constructor\n";
}
AMateria::AMateria(const AMateria& other) { *this = other; }
AMateria&   AMateria::operator=(const AMateria& other)
{
    if ( this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
AMateria::AMateria(){}

AMateria::~AMateria(){}

std::string const& AMateria::getType() const { return _type; }
// AMateria* AMateria::clone() const {}
void AMateria::use(ICharacter& target)  { 
    (void)target;
    std::cout<< "Not Used\n";
}
