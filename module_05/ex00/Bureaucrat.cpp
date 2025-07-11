#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
        
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}



int	Bureaucrat::getGrade() const
{
    return _grade;
}

const std::string&	Bureaucrat::getName() const
{
    return _name;
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat& Obj)
{
    outputStream << Obj.getName() << ", bureaucrat grade " << Obj.getGrade()<<"."<< std::endl;
    return outputStream;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low ";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High ";
}