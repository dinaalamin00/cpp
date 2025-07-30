#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>


// class notFound : public std::exception
// {
//     public:
//         const char* what() const throw();
// };

template <typename T>
typename T::const_iterator    easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("not found");
    return it;
}


#endif