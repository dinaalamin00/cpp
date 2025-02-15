#include "phonebook.hpp"
#include "contact.hpp"
#include <iomanip>


Contact::Contact(){}
Contact::~Contact(){}

void    Contact::setContact()
{
    // std::cout<<"Enter First Name: ";
    // std::cin>>firstName;
    // std::cout<<"Enter Last Name: ";
    // std::cin>>lastName;
    // std::cout<<"Enter  nickName: ";
    // std::cin>>nickName;
    // std::cout<<"Enter PhoneNumber: ";
    // std::cin>>phoneNumber;
    // std::cout<<"Enter darkestSecret: ";
    // std::cin>>darkestSecret;
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

void    Contact::displayContact(int index) const
{
    std::cout<<std::setw(10) << index << "|"
            << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
            << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
            << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName) << std::endl;
}

void    Contact::displayFullInfo() const
{
    std::cout<<"First Name: "<< firstName << std::endl;
    std::cout<<"Last Name: "<< lastName << std::endl;
    std::cout<<"NickName: "<< nickName << std::endl;
    std::cout<<"Phone Number: "<< phoneNumber << std::endl;
    std::cout<<"Darkest Secret: "<< darkestSecret << std::endl;
}