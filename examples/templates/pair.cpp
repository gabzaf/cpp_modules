#include <iostream>
#include <string>

//Class templates like function templates, are useful when a class defines something that is
//independent of the data type. It is useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc.
template <typename T1, typename T2> class Pair
{
    public:
        T1 first;
        T2 second;

        Pair(T1 f, T2 s) : first(f), second(s) {}

        void print() const
        {
            std::cout << "(" << first << ", " << second << ")" << std::endl;
        }
};

int main()
{
    // Creating a Pair of integers
    Pair<int, int> p1(10, 20);
    std::cout << "Pair of ints: ";
    p1.print();

    // Creating a Pair of a string and a double
    Pair<std::string, double> p2("Hello", 3.14);
    std::cout << "Pair of string and double: ";
    p2.print();

    // Creating a Pair of a char and a boolean
    Pair<char, bool> p3('A', true);
    std::cout << "Pair of char and bool: ";
    p3.print();

    return (0);
}