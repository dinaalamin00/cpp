#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp" 

int main()
{

    // Animal a;                         // Should not compile
    // Animal* a = new Animal();        //  Should not compile

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    dog->makeSound();    // Woof!!!!
    cat->makeSound();    // Meow!!!

    std::cout << "\n--- Destruction ---" << std::endl;
    delete dog;
    delete cat;

    std::cout << "\n--- Array Test ---" << std::endl;
    AAnimal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    return 0;
}
