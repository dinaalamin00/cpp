#include <iostream>
#include <string>
#include "Serializer.hpp"
#include "Data.hpp"


int main()
{
    Data* original = new Data;
    original->key = "Test";
    original->value = 42;

    std::cout << "Original pointer: " << original << '\n';
    std::cout << "Original data: " << original->value << ", " << original->key << '\n';

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored pointer: " << restored << '\n';
    if (restored)
        std::cout << "Restored data: " << restored->value << ", " << restored->key << '\n';
    else
        std::cout << "Restored is a null pointer.\n";
    
    if (original == restored)
        std::cout << "---- Success ----\n";
    else
        std::cout << "---- Failure ----\n";

    delete original;
    return 0;
}


