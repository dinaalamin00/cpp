#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called\n";
    _type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "WrongCat copy Constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void WrongCat::makeSound() const // Not overriding due to lack of virtual in base
{
    std::cout << "Meow? (Wrong version!)\n";
}
