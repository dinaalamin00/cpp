
#include "Dog.hpp"


Dog::Dog()
{
	std::cout<< "Dog Default Constructor called" <<std::endl;
}

Dog::Dog (const std::string &_type) : type(_type)
{
	std::cout<< "Dog Default Constructor called" <<std::endl;
}


Dog& Dog::operator=(const Dog& other) {
    std::cout<< "Dog Assignment Constructor called" <<std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Dog::Dog(const Dog& other)
{
    std::cout<< "Dog Copy Constructor called" <<std::endl;
	*this = other;
}

Dog::~Dog()
{
    std::cout<< "Dog Destructor called" <<std::endl;
}

void    Dog::makeSound()
{
    std::cout<< "Dog Sound!!!" <<std::endl;
}