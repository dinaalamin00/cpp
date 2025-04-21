#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}



// ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : _name(name) {}

AForm::AForm(const AForm& other) : _name(other._name), _grade_toSign(other._grade_toSign), _grade_toExec(other._grade_toExec){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void)other;
    return *this;
}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream OutFile(executor.getName() + "_shrubbery ");

    OutFile << "               ,@@@@@@@,\n"
        << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o\n"
        << "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'\n"
        << "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'\n"
        << "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'\n"
        << "   `&%\ ` /%&'    |.|        \ '|8'\n"
        << "       |o|        | |         | |\n"
        << "       |.|        | |         | |\n"
        << "jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_\n" << std::endl;

        OutFile.close();
}
