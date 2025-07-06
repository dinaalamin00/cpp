#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal* animal[6];
   
    for (unsigned int i = 0; i < 3; i++)
        animal[i] = new Dog();
    for (unsigned int i = 0; i < 3; i++)
        animal[i + 3] = new Cat();

    for (unsigned int i = 0; i < 6; i++)
        delete animal[i];

    Dog test;
    Dog test2 = test;
    return 0;
}