#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
int main()
{
    std::srand(std::time(0));

    for (int i = 0; i < 5; ++i)
    {
        Base* obj = generate();
        std::cout << "identify(Base*): ";
        identify(obj);
        std::cout << "identify(Base&): ";
        identify(*obj);
        delete obj;
        std::cout << "-----------------------\n";
    }

    return 0;
}
