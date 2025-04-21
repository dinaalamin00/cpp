#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Intern : public AForm
{
    private:
        /* data */
    public:
        Intern(/* args */);
        ~Intern();
        AForm   *makeForm(const std::string& fName, const std::string& target);
};

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

#endif