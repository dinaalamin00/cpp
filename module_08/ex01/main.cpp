// #include <iostream>
#include "Span.hpp"
// #include <cstdlib>

int main()
{
    std::cout << "Basic test:\n";
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nLarge range test:\n";
    try {
        Span spLarge = Span(10000);
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; ++i)
            bigVec.push_back(rand());

        spLarge.addNumbers(bigVec.begin(), bigVec.end());

        std::cout << "Shortest span: " << spLarge.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spLarge.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
