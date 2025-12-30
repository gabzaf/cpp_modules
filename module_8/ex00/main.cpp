#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    int arr[] = {-1345, -3, 0, 1, 42, 1234142};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    std::list<int> l(arr, arr + sizeof(arr)/sizeof(arr[0]));

    std::cout << "Vector Testing" << std::endl << std::endl;
    try
    {
        easyfind(v, -1345);
        easyfind(v, -1);
        easyfind(v, 42);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "List Testing" << std::endl << std::endl;
    try
    {
        easyfind(l, -1345);
        easyfind(l, 42);
        easyfind(l, -1);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
