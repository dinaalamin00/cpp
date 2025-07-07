
#include "Animal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout<< "AAnimal Default Constructor called" <<std::endl;
}

AAnimal::AAnimal (const std::string &type) : _type(type)
{
	std::cout<< "AAnimal Constructor called" <<std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout<< "AAnimal Assignment Constructor called" <<std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AAnimal::AAnimal(const AAnimal& other)
{
    std::cout<< "AAnimal Copy Constructor called" <<std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
    std::cout<< "AAnimal Destructor called" <<std::endl;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

