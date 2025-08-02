#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int        _maxSize;
        std::vector<int>    _numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span&   operator=(const Span& other);
        ~Span();

        void    addNumber(int num);
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan() const;
        int     longestSpan() const;



};



#endif