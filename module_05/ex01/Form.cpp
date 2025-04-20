#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form(){}

Form::Form(const std::string &name, const int grade_sign, const int grade_exec) : _name(name), _signed(false), _grade_toSign(grade_sign), _grade_toExec(grade_exec)
{
    if (_grade_toSign < 1 || _grade_toExec < 1)
        throw GradeTooHighException();
        
    if (_grade_toSign > 150 || _grade_toExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _grade_toSign(other._grade_toSign), _grade_toExec(other._grade_toExec){}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

const std::string&	Form::getName() const { return _name; }
bool	Form::getSign() const {  return _signed;}
int	    Form::getGradeSign() const { return _grade_toSign; }
int	    Form::getGradeExec() const { return _grade_toExec; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low";
}
std::ostream& operator<<(std::ostream &outputStream, const Form& Obj)
{
    outputStream <<"Form: "<< Obj.getName()
        << ", Signed: " << (Obj.getSign()? "yes ": "no ")
        <<", grade to sign: "<< Obj.getGradeSign()
        << ", grade to execute: "<< Obj.getGradeExec()
        <<"."<< std::endl;
    return outputStream;
}

void    Form::beSigned(const Bureaucrat &B)
{
    if (B.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    this->_signed = true;

}
