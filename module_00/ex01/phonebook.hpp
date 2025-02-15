#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include<iostream>
# include <string>
#include "contact.hpp"

class phoneBook{
    private:
        Contact contact[8];
        int     contactCount;
        int     oldestIndex;
    public:
        phoneBook();
        ~phoneBook();
        void    addContact();
        void    searchContact() const;
        void    displayAllContact() const;
        // int     isFull() const;
};

#endif