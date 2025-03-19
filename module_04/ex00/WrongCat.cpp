#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat constructor called\n";
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() 
{
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const { // ❌ Not overriding due to lack of virtual in base
    std::cout << "Meow? (Wrong version!)\n";
}
