#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5) ,_target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void)other;
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::canExecute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}