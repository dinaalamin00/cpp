#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook.hpp"

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        void    setContact();
        void    displayContact(int index) const;
        void    displayFullInfo() const;
        ~Contact();
};
#endif