#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called\n";
    type = "WrongAnimal";
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
        this->type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound!\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}
