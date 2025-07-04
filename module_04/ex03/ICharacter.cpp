#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::ICharacter() {
    std::cout<< "ICharacter Constructor\n";

}

ICharacter::ICharacter(const std::string& name) {
    this->_name = name;
    // (void)name;
}

ICharacter::ICharacter(const ICharacter& other) {  *this = other;}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    // (void)other;
    if (this != &other)
    {
        this->_name = other._name;
    }
    return *this;
}

ICharacter::~ICharacter() {}
