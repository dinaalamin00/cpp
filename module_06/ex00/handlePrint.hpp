#ifndef HANDLEPRINT_HPP
# define HANDLEPRINT_HPP

#include "ScalarConverter.hpp"


void    handleInt(const std::string& literal);
void    handlefd(const std::string& literal);
void    handleChar(char c);

void    handlePseudoLitral(const std::string& literal);

#endif