#include <iostream>
#include <vector>

//What are containers? Ready to use data structures.
//Containers are implemented using templates: template <typename T> class vector{}
//The vector container is itself a template.

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Vector elements: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Vector size: " << numbers.size() << std::endl;

    numbers.pop_back();
    std::cout << "Vector after pop_back: ";
    for (int num : numbers)
    {
       std::cout << num << " ";
    }
    std::cout << std::endl;
    return (0);
}