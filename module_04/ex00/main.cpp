#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n------------ Types ------------\n";
    std::cout << "\nDog Type: " << dog->getType() << std::endl;
    std::cout << "Cat Type: " << cat->getType() << std::endl;
    std::cout << "Animal Type: " << animal->getType() << std::endl;

    std::cout << "\n------------ Sounds ------------\n";
    animal->makeSound();
    dog->makeSound();  
    cat->makeSound();  

    std::cout << "\n--------- Deleting Animals ----------\n";
    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n\n--------- WrongAnimal and a WrongCat --------------\n\n";
    
    const WrongAnimal* wanimal = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();
    std::cout << "\n------------ wTypes ------------\n";
    std::cout << "WrongAnimal type: " << wanimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wcat->getType() << std::endl;

    std::cout << "\n------------ WSounds ------------\n";
    wanimal->makeSound();
    wcat->makeSound();    // Expected: "Some generic wrong animal sound!" (Not "Meow?")
    
    delete wanimal;
    delete wcat;

    return 0;
}