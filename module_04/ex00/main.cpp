#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal(); // Creates an Animal (can be empty type)
    const Animal* j = new Dog();       // Creates a Dog
    const Animal* i = new Cat();       // Creates a Cat
    
    std::cout << j->getType() << std::endl; // Output the type of Dog
    std::cout << i->getType() << std::endl; // Output the type of Cat
    
    i->makeSound(); // Will output the Cat sound
    j->makeSound(); // Will output the Dog sound
    
    // Cleanup
    delete meta;
    delete j;
    delete i;

    return 0;
}