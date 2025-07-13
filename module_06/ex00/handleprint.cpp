#include "ScalarConverter.hpp"
#include "handlePrint.hpp"

void    handleInt(const std::string& literal)
{
    long val = std::strtol(literal.c_str(), NULL, 10);

    if (val < INT_MIN || val > INT_MAX) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;}
     int i = static_cast<int>(val);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";

        std::cout << "int: " << i << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << '\n';
        return;

}
void    handlefd(const std::string& literal)
{
     double d = std::strtod(literal.c_str(), NULL);

        char c = static_cast<char>(d);
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);

       

        if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            std::cout << "char: impossible\n";
        else if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << i << '\n';

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << '\n';
        return;
}

void    handleChar(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << i << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << '\n';
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
