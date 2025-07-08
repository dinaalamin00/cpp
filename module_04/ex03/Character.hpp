#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ICharacter.hpp"


class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _materias[4];
        AMateria* _floor[100];
        unsigned int _floorIdx;
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const& getName() const;
        AMateria*   const& getMateria(unsigned int idx) const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
};

#endif
