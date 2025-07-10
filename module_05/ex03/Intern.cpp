#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm   *Intern::makeForm(const std::string& fName, const std::string& target)
{
    std::string formNames[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

    for(int i=0; i<3 && formNames[i] != fName; i++)
    
        switch(i)
        {
            case 0:
            {
                std::cout << "Intern creates " << fName << std::endl;
                return (new ShrubberyCreationForm(target));
            }
            case 1:
            {
                std::cout << "Intern creates " << fName << std::endl;
                return (new RobotomyRequestForm(target));
            }
            case 2:
            {
                std::cout << "Intern creates " << fName << std::endl;
                return (new PresidentialPardonForm(target));
            }
            default :
                std::cout << "Form \"" << fName << "\" not found." << std::endl;
        }
    return NULL;
}
