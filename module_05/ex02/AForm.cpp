#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm(){}

AForm::AForm(const std::string &name, const int grade_sign, const int grade_exec) : _name(name), _signed(false), _grade_toSign(grade_sign), _grade_toExec(grade_exec)
{
    if (_grade_toSign < 1 || _grade_toExec < 1)
        throw GradeTooHighException();
        
    if (_grade_toSign > 150 || _grade_toExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _grade_toSign(other._grade_toSign), _grade_toExec(other._grade_toExec){}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

const std::string&	AForm::getName() const { return _name; }
bool	AForm::getSign() const {  return _signed;}
int	    AForm::getGradeSign() const { return _grade_toSign; }
int	    AForm::getGradeExec() const { return _grade_toExec; }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade Too Low";
}
std::ostream& operator<<(std::ostream &outputStream, const AForm& Obj)
{
    outputStream <<"AForm: "<< Obj.getName()
        << ", Signed: " << (Obj.getSign()? "yes ": "no ")
        <<", grade to sign: "<< Obj.getGradeSign()
        << ", grade to execute: "<< Obj.getGradeExec()
        <<"."<< std::endl;
    return outputStream;
}

void    AForm::beSigned(const Bureaucrat &B)
{
    if (B.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    this->_signed = true;

}
