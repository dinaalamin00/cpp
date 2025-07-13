#include "ScalarConverter.hpp"
#include "handlePrint.hpp"

void    handleInt(const std::string& literal)
{
    long val = std::strtol(literal.c_str(), NULL, 10);

    if (val < INT_MIN || val > INT_MAX)
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (std::isprint(static_cast<char>(val)))
        std::cout << "char: '" << static_cast<char>(val) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << static_cast<int>(val) << '\n';
    std::cout<< std::fixed << std::setprecision(1);
    std::cout << "float: "  << static_cast<float>(val) << "f\n";
    std::cout << "double: " << static_cast<double>(val) << '\n';
}
void    handlefd(const std::string& literal)
{
     double d = std::strtod(literal.c_str(), NULL);

    if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
        std::cout << "char: impossible\n";
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else
        std::cout << "char: Non displayable\n";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << '\n';
    std::cout<< std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << '\n';
}

void    handleChar(char c)
{
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << '\n';
    std::cout<< std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << '\n';
    return;
}

void    handlePseudoLitral(const std::string& literal)
{
        bool isFloat = (literal[literal.length() - 1] == 'f');

        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << (isFloat ? "" : "f") << '\n';
        std::cout << "double: " << (isFloat ? literal.substr(0, literal.size()-1) : literal) << '\n';
}
