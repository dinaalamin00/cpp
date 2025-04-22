#ifndef ROBOROMYREQUESTFORM_HPP
# define ROBOROMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdbool.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>


// class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        // int _gradeSign = 72;
        // int _gradeExec = 45;
        std::string    _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&	operator=(const RobotomyRequestForm &other);

        ~RobotomyRequestForm();
        void    execute(Bureaucrat const & executor) const;
};


#endif