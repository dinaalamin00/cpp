#ifndef AForm_HPP
#define AForm_HPP

#include <stdbool.h>
#include <iostream>
#include <string>
#include <exception>



class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int           _grade_toSign;
        const int       _grade_toExec;
        bool                _signed;
    public:
        AForm();
        AForm(const std::string &name, int grade_sign, int grade_exec);
        AForm(const AForm &other);
        AForm&	operator=(const AForm &other);
        ~AForm();

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException  : public std::exception
        {
            const char* what() const throw();
        };

        class NotSignedException  : public std::exception
        {
            const char* what() const throw();
        };

        //getters
        const std::string&	getName() const;
        bool	getSign() const;
        int	getGradeSign() const;
        int	getGradeExec() const;

        void    beSigned(const Bureaucrat &B);

        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &outputStream, const AForm& Obj);

#endif

