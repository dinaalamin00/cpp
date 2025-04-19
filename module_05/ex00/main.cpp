#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  B1("B1", 150);
        std::cout<< B1 <<std::endl;
        
        B1.incrementGrade();
        std::cout<< B1 <<std::endl;

        B1.decrementGrade();
        std::cout<< B1 <<std::endl;
        
        B1.decrementGrade(); // exception thrown
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat  B2("B1", 1);
        std::cout<< B2 <<std::endl;

        B2.decrementGrade();
        std::cout<< B2 <<std::endl;

        B2.incrementGrade();
        std::cout<< B2 <<std::endl;

        B2.incrementGrade(); // exception thrown
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
