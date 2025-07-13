#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer(const Serializer &other);
        Serializer();
    public:
        Serializer&	operator=(const Serializer &other);
        ~Serializer();
    
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};




#endif