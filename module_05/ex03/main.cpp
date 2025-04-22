#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat bob("Bob", 1);

    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    if (form1) {
        bob.signForm(*form1);
        bob.executeForm(*form1);
        delete form1;
    }

    AForm* form2 = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form2) {
        bob.signForm(*form2);
        bob.executeForm(*form2);
        delete form2;
    }

    AForm* form3 = intern.makeForm("shrubbery creation", "Garden");
    if (form3) {
        bob.signForm(*form3);
        bob.executeForm(*form3);
        delete form3;
    }

    AForm* form4 = intern.makeForm("invalid form", "Nobody");
    if (form4) {
        delete form4;
    }

    return 0;
}
