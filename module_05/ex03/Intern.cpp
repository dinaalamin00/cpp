#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm   *Intern::makeShrubberyForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm   *Intern::makeRobotomyForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::makePresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(const std::string& fName, const std::string& target)
{
    std::string formNames[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    AForm *(Intern::*f[3])(const std::string& target) = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == fName)
        {
            std::cout << "Intern creates " << fName << std::endl;
            return ((this->*f[i])(target));
        }
    }
    std::cout << "Form \"" << fName << "\" not found." << std::endl;
    return NULL;
}
