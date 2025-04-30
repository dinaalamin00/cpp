#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}


static void convert(std::string str)
{
    std::cout<<"char: "<< static_cast<char>(str) <<std::endl;
    std::cout<<"int: "<< static_cast<int>(str) <<std::endl;
    std::cout<<"float: "<< static_cast<float>(str) <<std::endl;
    std::cout<<"double: "<< static_cast<double>(str) <<std::endl;

}
