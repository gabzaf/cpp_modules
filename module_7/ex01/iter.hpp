#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func> void iter(T *array, size_t len, Func func)
{
    size_t i = 0;

    if (!array)
        return;
    while (i < len)
    {
        func(array[i]);
        i++;
    }
};

#endif