#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Character::Character(){}

Character::Character(const std::string& name) : _name(name)
{
    for(unsigned int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

Character::Character(const Character& other)
{
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (unsigned int i = 0; i < 4; i++)
            this->_materias[i] = other._materias[i];
    }
    return *this;
}

Character::~Character()
{
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

std::string const& Character::getName() const{    return _name;}

void    Character::equip(AMateria* m)
{
    for(unsigned int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL && m)
        {
            _materias[i] = m;
            std::cout << m->getType() + " is equiped by " + this->getName() + "\n";
            return ;
        }
    }
    std::cout << getName() << ": CAN'T EQUIP MATERIA\n";
    return ;
}
void    Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0 && _materias[idx])
        _materias[idx] = NULL;
    return ;
}

void    Character::use(int idx, ICharacter& target)
{

    if (idx < 4 && idx >= 0 && _materias[idx]) {
        _materias[idx]->use(target); }
    return ;
}