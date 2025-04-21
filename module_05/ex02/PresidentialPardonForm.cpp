#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(/* args */){}

PresidentialPardonForm::~PresidentialPardonForm(){}

// PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : _name(name) {}

AForm::AForm(const AForm& other) : _name(other._name), _grade_toSign(other._grade_toSign), _grade_toExec(other._grade_toExec){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void)other;
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

}