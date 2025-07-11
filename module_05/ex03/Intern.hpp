#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm; 
class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm   *makeForm(const std::string& fName, const std::string& target);
        AForm   *makeShrubberyForm(const std::string& target);
        AForm   *makeRobotomyForm(const std::string& target);
        AForm   *makePresidentialPardonForm(const std::string& target);
};



#endif