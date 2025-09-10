#include "Array.hpp"
#include <iostream>

#include "Array.hpp"
#include <iostream>

template <typename T>
void printArrayInfo(Array<T> &array)
{
    std::cout << "Size of array: " << array.size() << std::endl;
    std::cout << "Elements of this array:" << std::endl;
    for (unsigned int i = 0; i < array.size(); i++)
    {
        std::cout << array[i];
        if (i != array.size() - 1)
            std::cout << " | ";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "*****  ARRAY OF INT TEST   *****" << std::endl;

    Array<int> num(10);

    for (unsigned int i = 0; i < 10; i++)
        num[i] = i + 10;

    printArrayInfo(num);

    std::cout << std::endl;

    return 0;
}
