
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 6);     
        Bureaucrat bob("Bob", 5);         
        Bureaucrat charlie("Charlie", 0); 

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford");

        // Signing forms
        charlie.signForm(shrub);  // Should succeed
        bob.signForm(robot);      // Should succeed
        alice.signForm(pardon);   // Should succeed

        std::cout << std::endl;

        // Executing forms
        charlie.executeForm(shrub); // Should succeed
        bob.executeForm(robot);     // Should succeed / fail 50%
        alice.executeForm(pardon);  // Should succeed

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
