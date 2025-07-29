#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void    iter(T* array, std::size_t size, void   (*f)(T&))
{
    for (std::size_t i = 0; i < size; ++i) {
        f(array[i]);
    }
}

template<typename T>
void    iter(const T* array, std::size_t size, void  ( *f)(T const&))
{
    for (std::size_t i = 0; i < size; ++i) {
        f(array[i]);
    }
}
#endif