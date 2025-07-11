#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) ,_target("defaul"){}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45) ,_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm ("RobotomyRequestForm", 72, 45), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::canExecute(executor);
    std::cout<< "Drilling noises..." <<std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2 )
        std::cout<< this->_target <<" has been robotomized successfully!"<<std::endl;
    else
        std::cout<< "Robotomy failed on " << this->_target << "." <<std::endl;
}