
#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	std::cout<< "Dog Default Constructor called" <<std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout<< "Dog Assignment Constructor called" <<std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Dog::Dog(const Dog& other) : Animal (other)
{
    std::cout<< "Dog Copy Constructor called" <<std::endl;
}

Dog::~Dog()
{
    std::cout<< "Dog Destructor called" <<std::endl;
}

void    Dog::makeSound() const
{
    std::cout<< "Woof!!!!" <<std::endl;
}