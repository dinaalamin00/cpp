#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal(); 
    ~WrongAnimal(); 
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);

    void makeSound() const; // Not virtual!
    std::string getType() const;
};

#endif
