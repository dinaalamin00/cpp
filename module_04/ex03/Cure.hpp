#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        /* data */
    public:
        Cure();
        Cure(const Cure& other);
        Cure&   operator=(const Cure& other);
        virtual ~Cure();

        AMateria*   clone() const;
        virtual void    use(ICharacter& target);

};


#endif