
#include "Dog.hpp"


Dog::Dog() : brain(new Brain())
{
    type = "Dog";
	std::cout<< "Dog Default Constructor called" <<std::endl;
}


Dog& Dog::operator=(const Dog& other) {
    std::cout<< "Dog Assignment Constructor called" <<std::endl;
    if (this != &other)
    {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Dog::Dog(const Dog& other) : Animal()
{
    std::cout<< "Dog Copy Constructor called" <<std::endl;
	*this = other;
}

Dog::~Dog()
{
    delete brain;
    std::cout<< "Dog Destructor called" <<std::endl;
}

void    Dog::makeSound() const
{
    std::cout<< "Woof!!!!" <<std::endl;
}