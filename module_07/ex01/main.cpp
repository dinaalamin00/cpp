#include "iter.hpp"

template<typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

template<typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

template<typename T>
void increment(T& x)
{
    ++x;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Original int array:" << std::endl;
    iter(arr, 5, print<int>);
    std::cout << "------------------------------------\n";
    
    iter(arr, 5, increment<int>);
    std::cout << "Incremented int array:" << std::endl;
    std::cout << "------------------------------------\n";

    iter(arr, 5, print<int>);
    std::cout << "------------------------------------\n";
    
    std::string strs[] = {"Hello", "World", "Templates"};
    std::cout << "String array:" << std::endl;
    iter(strs, 3, print<std::string>);
    std::cout << "------------------------------------\n";

    const int constArr[] = {10, 20, 30};
    std::cout << "Const int array:" << std::endl;
    iter(constArr, 3, print<int>);
    std::cout << "------------------------------------\n";

    const std::string sarr[] = {"hello", "world", "const!"};
    std::cout << "Const String array:" << std::endl;
    iter(sarr, 3, print);
    return 0;
}