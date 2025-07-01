#include <iostream>
#include <unordered_set>
#include <unordered_map>

//These containers store elements using hash tables, allowing for average constant-time access

void unordered_associative_containers()
{    
    // std::unordered_set: Stores unique elements, no specific order.
    std::cout << "\n[Unordered Set]" << std::endl;
    std::unordered_set<int> us = {5, 3, 4, 1, 2, 2};
    for (int i : us) 
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // std::unordered_map: Stores key-value pairs, no specific order.
    std::cout << "\n[Unordered Map]" << std::endl;
    std::unordered_map<std::string, int> um;
    um["one"] = 1;
    um["three"] = 3;
    um["two"] = 2;
    for (const auto& pair : um)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main()
{
    unordered_associative_containers();
    return (0);
}