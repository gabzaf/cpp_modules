#include "iter.hpp"

template<typename T> void print(const T &value) { std::cout << value << " "; }

template<typename T> void increment(T &value) { value++; }

template<typename T> void makeUpper(T &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

void printInt(const int &n) { std::cout << n << " "; }

void doubleValue(int &n) { n *= 2; }

void printChar(const char &c) { std::cout << c; }

int main()
{
    std::cout << "=== Testing iter function template ===" << std::endl;

    std::cout << "\n1. Integer array with print function template:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numSize = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original: ";
    iter(numbers, numSize, print<int>);
    std::cout << std::endl;

    std::cout << "\n2. Incrementing each element:" << std::endl;
    iter(numbers, numSize, increment<int>);
    std::cout << "After increment: ";
    iter(numbers, numSize, print<int>);
    std::cout << std::endl;

    std::cout << "\n3. Doubling each element with regular function:" << std::endl;
    iter(numbers, numSize, doubleValue);
    std::cout << "After doubling: ";
    iter(numbers, numSize, printInt);
    std::cout << std::endl;

    std::cout << "\n4. Character array:" << std::endl;
    char text[] = {'h', 'e', 'l', 'l', 'o'};
    size_t textSize = sizeof(text) / sizeof(text[0]);
    
    std::cout << "Original: ";
    iter(text, textSize, printChar);
    std::cout << std::endl;

    iter(text, textSize, makeUpper<char>);
    std::cout << "After makeUpper: ";
    iter(text, textSize, printChar);
    std::cout << std::endl;

    std::cout << "\n5. String array:" << std::endl;
    std::string words[] = {"Hello", "World", "From", "iter"};
    size_t wordsSize = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Strings: ";
    iter(words, wordsSize, print<std::string>);
    std::cout << std::endl;

    std::cout << "\n6. Const array (read-only operations):" << std::endl;
    const double constants[] = {3.14, 2.71, 1.41, 1.73};
    size_t constSize = sizeof(constants) / sizeof(constants[0]);
    
    std::cout << "Constants: ";
    iter(constants, constSize, print<double>);
    std::cout << std::endl;

    std::cout << "\n7. Float array:" << std::endl;
    float decimals[] = {1.1f, 2.2f, 3.3f};
    size_t decimalsSize = sizeof(decimals) / sizeof(decimals[0]);
    
    std::cout << "Original floats: ";
    iter(decimals, decimalsSize, print<float>);
    std::cout << std::endl;
    
    iter(decimals, decimalsSize, increment<float>);
    std::cout << "After increment: ";
    iter(decimals, decimalsSize, print<float>);
    std::cout << std::endl << std::endl;

    const int carr[] = {1, 2, 3};
    iter(carr, 3, print<int>);

    return (0);
}