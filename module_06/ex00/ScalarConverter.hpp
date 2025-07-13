#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>      // strtod, strtof, strtol
#include <climits>      // INT_MAX, INT_MIN
#include <cfloat>       // FLT_MAX
#include <cctype>       // isprint
#include <limits>
#include "handlePrint.hpp"


class ScalarConverter
{
    
    private:
        ScalarConverter();                           
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
        
        static bool isChar(std::string const& str);
        static bool isInt(std::string const& str);
        static bool isFloat(std::string const& str);
        static bool isDouble(std::string const& str);
        static bool isPseudoLiteral(std::string const& str);

    public:
        static void convert(std::string const& literal);
};



#endif