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

	Array<int> a(3);
	a[0] = 10;

	const Array<int> b(a);
	std::cout << b[0] << std::endl;

	Array<std::string> words(3);
    	words[0] = "Hello";
    	words[1] = "42";
   	words[2] = "Porto";

    	for (unsigned int i = 0; i < words.size(); i++)
        	std::cout << words[i] << std::endl;
	return 0;
}
