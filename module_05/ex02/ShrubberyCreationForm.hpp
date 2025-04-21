#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdbool.h>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"



class ShrubberyCreationForm : public AForm
{
    private:
        int _gradeSign = 145;
        int _gradeExec = 137;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        void    execute(Bureaucrat const & executor) const;

};



#endif