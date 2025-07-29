#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
template <typename T>
class Array
{
    private:
        T*   _arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array&   operator=(const Array& other);
        ~Array();

        T&  operator[](unsigned int idx);
        const T&  operator[](unsigned int idx) const;
        unsigned int size() const;

        class OutOfBound : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"
#endif