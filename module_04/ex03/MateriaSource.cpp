#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout<< "MateriaSource Constructor\n";

    for(unsigned int i = 0; i < 4; i++)
    {
        // std::cout << i << std::endl;
        _materia_storage[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other){ *this = other; }
MateriaSource&   MateriaSource::operator=(const MateriaSource& other)
{
    (void)other;
    // if ( this != &other)
    // {
    //     this->_type = other._type;
    // }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materia_storage[i])
            delete _materia_storage[i];
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    // AMateria* _m = m->clone();

    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materia_storage[i] == NULL)
            _materia_storage[i] = m;
                return ;
    }
    return ;
}
AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materia_storage[i])
            if (_materia_storage[i]->getType() == type)
                return _materia_storage[i]->clone();
    }
    return 0;
}