#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Creating Animals:\n";
    
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nGetting Types:\n";
    std::cout << "Dog Type: " << dog->getType() << std::endl;
    std::cout << "Cat Type: " << cat->getType() << std::endl;
    std::cout << "Meta Type: " << meta->getType() << std::endl;

    std::cout << "\nMaking Sounds:\n";
    meta->makeSound();
    dog->makeSound();  
    cat->makeSound();  

    std::cout << "\nDeleting Animals:\n";
    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n\n-----------------------------------------------------\n\n";

    std::cout << "Creating a WrongAnimal and a WrongCat:\n";
    
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << "WrongAnimal type: " << wmeta->getType() << std::endl;
    std::cout << "WrongCat type: " << i->getType() << std::endl;

    std::cout << "Making sounds:\n";
    wmeta->makeSound(); // Expected: "Some generic wrong animal sound!"
    i->makeSound();    // Expected: "Some generic wrong animal sound!" (Not "Meow?")
    
    delete wmeta;
    delete i;

    return 0;
}