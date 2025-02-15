#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook(){}
void    PhoneBook::addContact()
{
    Contact newContact;

    newContact.setContact();
    if (contactCount < 8)
    {
        contact[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        contact[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void    PhoneBook::searchContact() const
{
    std::string input;
    std::cout<< "Enter an Index: " << std::endl;
    std::getline(std::cin, input);
    check_empty_input(input, "an Index");
    
    int     index = -1;
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
        index = input[0] - '0';
    if (index < 0 || index >= contactCount)
        std::cout<<"Invalid Index!" << std::endl;
    else
        contact[index].displayFullInfo();
}

void    PhoneBook::displayAllContact() const
{
    if (contactCount == 0)
        std::cout<<"PhoneBook is empty!" << std::endl;
    else
    {
        std::cout<< "+--------------------------------------+" << std::endl;
        std::cout<< "|Index|First Name|Last Name | NickName |" << std::endl;
        std::cout<< "+--------------------------------------+" << std::endl;
        for (int i = 0; i < contactCount; i++)
            contact[i].displayContact(i);
        std::cout<< "+--------------------------------------+" << std::endl;
        searchContact();
    }
}
