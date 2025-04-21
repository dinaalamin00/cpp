#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : _target(target) {}

AForm::AForm(const AForm& other) : _name(other._name), _grade_toSign(other._grade_toSign), _grade_toExec(other._grade_toExec){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!getSign())
        throw NotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::cout<< "Drilling noises..." <<std::endl;

    if (std::rand() % 2 )
        std::cout<< this->_target <<" has been robotomized successfully!"<<std::endl;
    else
        std::cout<< "Robotomy failed on " << this->_target << "." <<std::endl;
}