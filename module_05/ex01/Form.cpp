#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(){}

Form::~Form(){}


Form::Form(const std::string &name, const int grade_sign, const int grade_exec) : _name(name), _grade_toSign(grade_sign), _grade_toExec(grade_exec)
{
    if (_grade_toSign < 1 || _grade_toExec < 1)
        throw GradeTooHighException();
        
    if (_grade_toSign > 150 || _grade_toExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
{
    *this = other;
}

Form& Form::operator=(const Form& other)
{
    (void)other;
    return *this;
}

const   std::string&	Form::getName() const
{
    return _name;
}

bool	Form::getSign() const
{
    return _signed;
}
int	Form::getGradeSign() const
{
    return _grade_toSign;
}
int	Form::getGradeExec() const
{
    return _grade_toExec;
}

std::ostream& operator<<(std::ostream &outputStream, const Form& Obj)
{
    outputStream << Obj.getName() << "Signed" <<Obj.getSign()<<" grade to sign: "<< Obj.getGradeSign()<< " grade to execute: "<< Obj.getGradeExec()<<"."<< std::endl;
    return outputStream;
}

void    Form::beSigned(Bureaucrat &B)
{
    if (Bureaucrat:: _grade < 1)
        throw GradeTooHighException();
        
    if (B._grade > 150)
        throw GradeTooLowException();
    this->_signed = true;
}
