#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

// class AMateria;
class IMateriaSource
{
    private:
    public:
        IMateriaSource(/* args */);
        IMateriaSource(const IMateriaSource& other);
        IMateriaSource&  operator=(const IMateriaSource& other);
    virtual ~IMateriaSource();
        virtual void    learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const& type) = 0;
};



#endif