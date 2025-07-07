
#include "Cat.hpp"


Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
	std::cout<< "Cat Default Constructor called" <<std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout<< "Cat Assignment Constructor called" <<std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
    std::cout<< "Cat Copy Constructor called" <<std::endl;
    brain = new Brain(*other.brain);

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