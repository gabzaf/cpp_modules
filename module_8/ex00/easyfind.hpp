#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>

typename T::iterator easyfind(T &container, int nbr)
{
    typename T::iterator it = std::find(container.begin(), container.end(), nbr);
    if (it == container.end())
        throw std::runtime_error("No occurrence of the input.");
    else
        std::cout << "Input found" << std::endl;
    return (it);
}

#endif
