#include <iostream>
#include <map>
#include <set>

//Associative containers store elements in a sorted order

void    associative_container_set()
{
    std::cout << "set" << std::endl;
    std::set<int> s = {5, 3, 8, 1, 2, 2, 0, 30};
    for (int i : s)
    {
        std::cout << i << std::endl;
    }
}

void    associative_container_map()
{
    std::map<std::string, int> m;
    std::cout << "map" << std::endl;
    m["one"] = 1;
    m["three"] = 3;
    m["two"] = 2;

    //std::cout << m["one"] << std::endl;
    for (const auto& pair : m)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main()
{
    associative_container_map();
    associative_container_set();
    return (0);
}