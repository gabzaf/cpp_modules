#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename Func> void iter(T *array, std::size_t const len, Func func)
{
	std::size_t i = 0;

	if (!array)
		return;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

template <typename T, typename Func> void iter(T const* array, std::size_t const len, Func func)
{
	std::size_t i = 0;

	if (!array)
		return;
 	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

#endif
