#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); ++i)
            numbers[i] = i * 10;

        Array<int> copy = numbers;
        copy[0] = 999;

        std::cout << "----------------------------\n";
        std::cout << "Original: ";
        for (unsigned int i = 0; i < numbers.size(); ++i)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        std::cout << "----------------------------\n";
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); ++i)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        std::cout << "----------------------------\n";
        std::cout << "Out of bounds access check: \n";
        std::cout << numbers[100] << std::endl; // should throw

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
