#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include<iostream>
# include <string>
#include "contact.hpp"

class phonebook{
    private:
        contact contact[8];
        int     contactCount;
        int     oldestIndex;
    public:
        void    addContact(){}
        void    searchContact() const;
        void    displayAllContact() const;
        int     isFull() const;
};

#endif