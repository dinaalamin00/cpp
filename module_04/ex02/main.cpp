#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " makes sound: "; j->makeSound();
    std::cout << i->getType() << " makes sound: "; i->makeSound();
    delete j;
    delete i;

    std::cout << "\nCreating an array of Animals:\n";
    Animal* animals[4];
    for (int i = 0; i < 2; i++) animals[i] = new Dog();
    for (int i = 2; i < 4; i++) animals[i] = new Cat();
    
    std::cout << "\nDeleting array of Animals:\n";
    for (int i = 0; i < 4; i++) delete animals[i];

    std::cout << "\nTesting deep copy:\n";
    Dog originalDog;
    Dog copiedDog = originalDog;
    Cat originalCat;
    Cat copiedCat = originalCat;
    return 0;
}