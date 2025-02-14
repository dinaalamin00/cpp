#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook.hpp"

class contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        contact(){}
        ~contact(){}
        void    setContact();
        void    displayContact(int index) const;
        void    displayAllContacts() const;

};
#endif