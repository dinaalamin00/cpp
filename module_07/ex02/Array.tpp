#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array& other) : _arr(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>&  Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete [] this->_arr;
        this->_size = other._size;
        this->_arr = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            this->_arr[i] = other._arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _arr;
}

template <typename T>
const char* Array<T>::OutOfBound::what() const throw()
{
    return "index is out of bounds";
}


template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= _size)
        throw   OutOfBound();
    return _arr[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= _size)
        throw   OutOfBound();
    return _arr[idx];
}


template <typename T>
unsigned int    Array<T>::size() const
{
    return _size;
}




#endif