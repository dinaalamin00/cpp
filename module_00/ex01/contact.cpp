#include "phonebook.hpp"
#include "contact.hpp"
#include <iomanip>


Contact::Contact(){}
Contact::~Contact(){}

void    check_empty_input(std::string input, std::string title)
{
    while (input.empty())
    {
        if ((std::cin.eof()))
        {
            std::cout<<std::endl;
            std::exit(1);
        }
        std::cout << "Enter "<<title;
        std::getline(std::cin, input);
    }
}

void    Contact::setContact()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    check_empty_input(firstName, "First Name: ");
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    check_empty_input(lastName, "Last Name: ");
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickName);
    check_empty_input(nickName, "NickName: ");
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    check_empty_input(phoneNumber, "Phone Number: ");
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    check_empty_input(darkestSecret, "Darkest Secret: ");
}

void    Contact::displayContact(int index) const
{
    std::cout<<"|"<<std::setw(5) << index << "|"
            << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
            << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
            << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName)<<"|"<< std::endl;
}

void    Contact::displayFullInfo() const
{
    std::cout<<"First Name: "<< firstName << std::endl;
    std::cout<<"Last Name: "<< lastName << std::endl;
    std::cout<<"NickName: "<< nickName << std::endl;
    std::cout<<"Phone Number: "<< phoneNumber << std::endl;
    std::cout<<"Darkest Secret: "<< darkestSecret << std::endl;
}