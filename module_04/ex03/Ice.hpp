#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        /* data */
    public:
        Ice();
        Ice(const Ice& other);
        Ice&   operator=(const Ice& other);
        virtual ~Ice();

        AMateria*    clone() const;
        virtual void    use(ICharacter& target) ;

};


#endif