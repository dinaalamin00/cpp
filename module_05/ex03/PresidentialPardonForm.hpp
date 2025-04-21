#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdbool.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// class AForm;
class PresidentialPardonForm : public AForm
{
    private:
        std::string    _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        void    execute(Bureaucrat const & executor) const;

};



#endif