#include <iostream>
#include <utility> // For std::pair
#include <string>

//std::pair is a class template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.
int main()
{
    std::pair<std::string, double> stdPair("Hello", 3.14);

    // Access elements
    std::cout << "std::pair: (" << stdPair.first << ", " << stdPair.second << ")" << std::endl;

    return (0);
}

//This is the basis for containers like std::vector, std::map, std::list, etc.
