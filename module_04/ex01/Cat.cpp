
#include "Cat.hpp"


Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout<< "Cat Default Constructor called" <<std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout<< "Cat Assignment Constructor called" <<std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout<< "Cat Copy Constructor called" <<std::endl;
}

Cat::~Cat()
{
    std::cout<< "Cat Destructor called" <<std::endl;
    delete brain;
}


void    Cat::makeSound() const
{
    std::cout<< "Meow!!!!" <<std::endl;
}