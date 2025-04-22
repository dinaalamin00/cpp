
#ifndef AForm_HPP
#define AForm_HPP

#include <stdbool.h>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>



class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool                _signed;
        const int           _grade_toSign;
        const int       _grade_toExec;
    public:
        AForm();
        AForm(const std::string &name, int grade_sign, int grade_exec);
        AForm(const AForm &other);
        AForm&	operator=(const AForm &other);
        virtual ~AForm();

        
        const std::string&  getName() const;
        bool	            getSign() const;
        int	                getGradeSign() const;
        int	                getGradeExec() const;
        
        class GradeTooHighException : public std::exception { const char* what() const throw();};
        class GradeTooLowException  : public std::exception { const char* what() const throw(); };
        class NotSignedException  : public std::exception { const char* what() const throw(); };
        
        void            beSigned(const Bureaucrat &B);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        void            canExecute(Bureaucrat const& B) const;
};

std::ostream& operator<<(std::ostream &outputStream, const AForm& Obj);

#endif

