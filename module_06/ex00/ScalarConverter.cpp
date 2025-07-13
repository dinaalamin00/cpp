#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(std::string const& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

bool ScalarConverter::isInt(std::string const& str)
{
    if (str.empty())
        return false;
    size_t  i = 0;
    if (str[i] == '+' || str[i] == '-')
        ++i;
    if (i == str.length())
        return false;
    for(; i<str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(std::string const& str)
{
    size_t i = 0;
    bool dotFound = false;

    if (str.empty() || str[str.length() - 1] != 'f')
        return false;

    std::string fstr = str.substr(0, str.length() - 1);

    if (fstr.empty())
        return false;

    if (fstr[i] == '+' || fstr[i] == '-')
        ++i;

    if (i == fstr.length())
        return false;

    bool digitFound = false;

    for (; i < fstr.length(); ++i)
    {
        if (fstr[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!isdigit(fstr[i]))
            return false;
        else
            digitFound = true;
    }
    return dotFound && digitFound;
}


bool ScalarConverter::isDouble(std::string const& str)
{
    size_t i = 0;
    bool dotFound = false;

    if (str.empty() || str[str.length() - 1] == 'f')
        return false;

    if (str == "nan" || str == "+inf" || str == "-inf")
        return false;

    if (str[i] == '+' || str[i] == '-')
        ++i;

    if (i == str.length())
        return false;

    bool digitFound = false;

    for (; i < str.length(); ++i) {
        if (str[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!isdigit(str[i]))
            return false;
        else
            digitFound = true;
    }

    return dotFound && digitFound;
}


bool ScalarConverter::isPseudoLiteral(std::string const& str)
{
    return ( str == "nan" || str == "+inf" || str == "-inf" ||
                str == "nanf" || str == "+inff" || str == "-inff" );
}


void ScalarConverter::convert(std::string const& literal)
{
    if (isChar(literal))
    {
        handleChar(literal[0]);
        return ;  
    }
    if (isInt(literal))
    {
       handleInt(literal);
        return;
    }
    if (isFloat(literal) || isDouble(literal))
    {
       handlefd(literal);
        return;
    }
    if (isPseudoLiteral(literal))
    {
       handlePseudoLitral(literal);
        return;
    }
    std::cout << "Invalid input.\n";
}