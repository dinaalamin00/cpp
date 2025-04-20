#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat  B1("B1", 50);
        Bureaucrat  B2("B2", 1);

        Form F1("F1", 30, 20);
        Form F2("F2", 100, 80);
        
        std::cout<< F1 <<std::endl;
        std::cout<< F2 <<std::endl;

        std::cout<<"---------------------------------------------------------\n";
        
        B1.signForm(F1);
        B1.signForm(F2);

        std::cout<<"---------------------------------------------------------\n\n";

        std::cout<< F1 <<std::endl;
        std::cout<< F2 <<std::endl;
        
        std::cout<<"---------------------------------------------------------\n";
        
        B2.signForm(F1);
        B2.signForm(F2);
        
        std::cout<<"---------------------------------------------------------\n\n";
        
        std::cout<< F1 <<std::endl;
        std::cout<< F2 <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
