
#include "Dog.hpp"


Dog::Dog() : AAnimal("Dog"),  brain(new Brain())
{
	std::cout<< "Dog Default Constructor called" <<std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout<< "Dog Assignment Constructor called" <<std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::Dog(const Dog& other) : AAnimal (other)
{
    std::cout<< "Dog Copy Constructor called" <<std::endl;
    brain = new Brain(*other.brain);
}

Dog::~Dog()
{
    std::cout<< "Dog Destructor called" <<std::endl;
    delete brain;
}

void    Dog::makeSound() const
{
    std::cout<< "Woof!!!!" <<std::endl;
}