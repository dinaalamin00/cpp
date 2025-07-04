#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
    protected:
        std::string _name;
    public:
        ICharacter();
        ICharacter(const std::string& name);
        ICharacter(const ICharacter& other);
        ICharacter& operator=(const ICharacter& other);
        virtual ~ICharacter();

        virtual std::string const& getName() const = 0;
        virtual void    equip(AMateria* m) = 0;
        virtual void    unequip(int idx) = 0;
        virtual void    use(int idx, ICharacter& target) = 0;
};

#endif
