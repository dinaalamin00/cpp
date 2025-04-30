#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(/* args */)
{
}

Base::~Base()
{
}

Base * generate(void);
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout<< "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout<< "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout<< "C" << std::endl;
}
void identify(Base& p)
{
    try
    {
        if (dynamic_cast<A&>(p))
            std::cout<< "A" << std::endl;
        else
        dynamic_cast<B&>(p);
        std::cout<< "B" << std::endl;
        dynamic_cast<C&>(p);
        std::cout<< "C" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}