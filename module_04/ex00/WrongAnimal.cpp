#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound!\n";
}

std::string WrongAnimal::getType() const
{
    return _type;
}
