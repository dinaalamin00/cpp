#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        /* data */
        const std::string	_name;
        int					_grade;
    public:
        Bureaucrat(/* args */);
        ~Bureaucrat();
        std::string	getName() const;
        int	getGrade() const;
        void incrementGrade();
        void decrementGrade();

};
std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat& Obj);


Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}



#endif