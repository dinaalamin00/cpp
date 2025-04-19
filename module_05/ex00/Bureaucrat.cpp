#include "Bureaucrat.hpp"

std::string	Bureaucrat::getName() const
{
	return _name;
}


int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat& Obj)
{
    outputStream << Obj.getName() << ", bureaucrat grade " << Obj.getGrade()<<"."<< std::endl;
    return outputStream;
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    if (_grade <= 0)
        throw GradeTooHighException();


}
void Bureaucrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}