#include <iostream>
#include <string>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{

    Data    data;
    Data    *ptr;
    uintptr_t      serial;

    data.value = 3;
    data.key = "KEY";
    ptr = NULL;

    std::cout<< "data address:" << &data<<std::endl;
    serial = Serializer::serialize(&data);
    std::cout<< "serialied:" << serial<<std::endl;
    ptr = Serializer::deserialize(serial);
    std::cout<< "-------------deserialied------------\naddress: " << ptr << "\nkey: "
        << ptr->key << " -- value: " << ptr->value<<std::endl;
    
    return 0;
}

