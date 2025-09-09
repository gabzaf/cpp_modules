#include "Serializer.hpp"

int main() {
    Data data;
    data.number = 42;

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data number: " << data.number << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    if (ptr == &data)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers do not match!" << std::endl;

    return (0);
}