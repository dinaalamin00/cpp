#include "phonebook.hpp"

int main()
{
    phoneBook   phonebook;
    std::string command;

    while(1)
    {
        std::cout<<"Enter a Command[ADD, SEARCH, EXIT]: "<<std::endl;
        std::getline(std::cin, command);
        if (std::cin.eof())
            break ;
        if (command== "EXIT")
            break ;
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else
            std::cout<<"Invalid Command!\n";
    }
    return 0;
}
