#include "contact.hpp"
#include "phonebook.hpp"


// contact::contact(){}

contact::setcontact()
{
    std::cout<<"Enter First Name: ";
    std::cin>>firstName;
    std::cout<<"Enter Last Name: ";
    std::cin>>lastName;
    std::cout<<"Enter  nickName: ";
    std::cin>>nickName;
    std::cout<<"Enter PhoneNumber: ";
    std::cin>>phoneNumber;
    std::cout<<"Enter darkestSecret: ";
    std::cin>>darkestSecret;

}

contact::displayContact(int index) const
{
    std::cout<<std::setw(10)  << index << "|"
}
        void    displayAllContacts() const;