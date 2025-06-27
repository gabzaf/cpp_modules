#include <iostream>
#include <string>

//template <typename T>: This declares maximum as a function template, where T is a placeholder for a data type.
template <typename T> T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Using the template with integers
    std::cout << "Max of 5 and 10: " << maximum(5, 10) << std::endl;

    // Using the template with doubles
    std::cout << "Max of 3.14 and 2.71: " << maximum(3.14, 2.71) << std::endl;

    // Using the template with strings (lexicographical comparison)
    std::cout << "Max of \"apple\" and \"banana\": " << maximum("apple", "banana") << std::endl;

    // The compiler automatically deduces the type T for each call.
    std::cout << "Max of 7 and 8 (explicit int): " << maximum<int>(7, 8) << std::endl;

    return (0);
}

