#include "Span.hpp"

void	printString(std::string stg)
{
	std::cout << stg << std::endl;
}

int main()
{
    try
    {
        printString("SUBJECT TEST");
        Span test1 = Span(5);
        test1.addNumber(6);
        test1.addNumber(3);
        test1.addNumber(17);
        test1.addNumber(9);
        test1.addNumber(11);
        test1.printNbrs();
        printString("Shortest Span");
        std::cout << test1.shortestSpan() << std::endl;
        printString("Longest Span");
        std::cout << test1.longestSpan() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}