#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}



ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137) ,_target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void)other;
    return *this;
}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::canExecute(executor);

    std::ofstream OutFile((executor.getName() + "_shrubbery ").c_str());  // change std::string to const char* 

    OutFile << "               ,@@@@@@@,\n"
    << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
    << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
    << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
    << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
    << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
    << "       |o|        | |         | |\n"
    << "       |.|        | |         | |\n"
    << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
    << std::endl;

        OutFile.close();
}
