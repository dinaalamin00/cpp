
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 1);       // Top-grade bureaucrat
        Bureaucrat bob("Bob", 50);          // Mid-grade bureaucrat
        Bureaucrat charlie("Charlie", 140); // Low-grade bureaucrat

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
