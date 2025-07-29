
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "Testing with std::vector:\n";
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);

    try 
    {
        std::vector<int>::const_iterator it = easyfind(vec, 5);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        easyfind(vec, 9);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting with std::list:\n";
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try 
    {
        std::list<int>::const_iterator it = easyfind(lst, 20);
        std::cout << "Found value in list: " << *it << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        easyfind(lst, 100);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
