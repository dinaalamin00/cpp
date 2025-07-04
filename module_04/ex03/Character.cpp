#include "Character.hpp"

Character::Character(): ICharacter(){}


Character::Character(const std::string& name) : ICharacter(name)
{
    std::cout<< "Character Constructor\n";
    for(unsigned int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
    }
}

Character::Character(const Character& other)  : ICharacter(other){}

Character& Character::operator=(const Character& other)
{
    (void) other;
    // if (this != &other)
    // {
    //     this->_name = other._name;
    // }
    return *this;
}

Character::~Character()
{
    // for(unsigned int i = 0; i < 4; i++)
    // {
    //     if (_materias[i])
    //         delete _materias[i];
    // }
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
        std::cout << _materias[idx]->getType() << std::endl;
        _materias[idx]->use(target); }
    return ;
}