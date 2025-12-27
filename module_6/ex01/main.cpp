#include "serializer.hpp"

int main() {
    data datta;
    datta.number = 42;

    std::cout << "Original Data address: " << &datta << std::endl;
    std::cout << "Original Data number: " << datta.number << std::endl;
    uintptr_t raw = Serializer::serialize(&datta);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
    data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    if (ptr == &datta)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers do not match!" << std::endl;

    return (0);
}
