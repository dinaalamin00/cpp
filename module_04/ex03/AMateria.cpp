#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria&   AMateria::operator=(const AMateria& other)
{
    if ( this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria::~AMateria(){}

// ------------ Getters ----------------

std::string const& AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
