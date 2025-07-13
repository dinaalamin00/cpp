#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void) other;
    return *this;
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

// ------------------------------------------------------

uintptr_t Serializer::serialize(Data* ptr)
{
     if (!ptr)
        std::cerr << "Warning: Trying to serialize a nullptr\n";
    return (reinterpret_cast<uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    if (raw == 0)
        std::cerr << "Warning: Deserializing from a 0 value → nullptr\n";
    return (reinterpret_cast<Data*> (raw));
}


