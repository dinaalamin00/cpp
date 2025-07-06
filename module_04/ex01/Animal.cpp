
#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout<< "Animal Default Constructor called" <<std::endl;
}

Animal::Animal (const std::string &type) : _type(type)
{
	std::cout<< "Animal Constructor called" <<std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout<< "Animal Assignment Constructor called" <<std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::Animal(const Animal& other)
{
    std::cout<< "Animal Copy Constructor called" <<std::endl;
	*this = other;
}

Animal::~Animal()
{
    std::cout<< "Animal Destructor called" <<std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}

void    Animal::makeSound() const
{
    std::cout<< "Animal Sound!!!" <<std::endl;
}
