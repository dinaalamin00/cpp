#include <iostream>
#include <string>
#include <stdexcept>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: need more Args" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn(argv[1]);
        double result = rpn.evaluate();
        std::cout << result << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "" << e.what() << std::endl;
        return 1;
    }

    return 0;
}
