#ifndef AFORM_HPP
#define AFORM_HPP

#include <stdbool.h>
#include <iostream>
#include <string>
#include <exception>



class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool                _signed;
        const int           _grade_toSign;
        const int       _grade_toExec;
    public:
        Form();
        Form(const std::string &name, int grade_sign, int grade_exec);
        Form(const Form &other);
        Form&	operator=(const Form &other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException  : public std::exception
        {
            const char* what() const throw();
        };

        //getters
        const std::string&	getName() const;
        bool	getSign() const;
        int	getGradeSign() const;
        int	getGradeExec() const;

        void    beSigned(const Bureaucrat &B);
};

std::ostream& operator<<(std::ostream &outputStream, const Form& Obj);

#endif

