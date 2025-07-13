
#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>

class Base
{
    private:
        /* data */
    public:
        Base();
        Base(const Base& other);
        Base&   operator =(const Base& other);
        virtual ~Base();
};
    
Base * generate(void);
void identify(Base* p);
void identify(Base& p);


#endif
