#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(unsigned int i = 0; i < 4; i++)
        _materia_storage[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other){ *this = other; }
MateriaSource&   MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for(unsigned int i = 0; i < 4; i++)
            this->_materia_storage[i] = other._materia_storage[i];
    }
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
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materia_storage[i] == NULL)
        {
            _materia_storage[i] = m;
            return ;
        }
    }
    return ;
}
AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materia_storage[i] && _materia_storage[i]->getType() == type)
            return (_materia_storage[i]->clone());
    }
    return 0;
}