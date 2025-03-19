
#include "Cat.hpp"


Cat::Cat()
{
	std::cout<< "Cat Default Constructor called" <<std::endl;
}

Cat::Cat (const std::string &_type) : type(_type)
{
	std::cout<< "Cat Default Constructor called" <<std::endl;
}


Cat& Cat::operator=(const Cat& other) {
    std::cout<< "Cat Assignment Constructor called" <<std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Cat::Cat(const Cat& other)
{
    std::cout<< "Cat Copy Constructor called" <<std::endl;
	*this = other;
}

Cat::~Cat()
{
    std::cout<< "Cat Destructor called" <<std::endl;
}


void    Cat::makeSound()
{
    std::cout<< "Cat don’t bark!!!" <<std::endl;
}