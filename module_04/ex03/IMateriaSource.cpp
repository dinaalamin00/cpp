#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
    std::cout<< "IMateriaSource Constructor\n";

}
IMateriaSource::IMateriaSource(const IMateriaSource& other) { *this = other; }
IMateriaSource&   IMateriaSource::operator=(const IMateriaSource& other)
{
    (void)other;
    // if ( this != &other)
    // {
    //     this->_type = other._type;
    // }
    return *this;
}

IMateriaSource::~IMateriaSource(){}
