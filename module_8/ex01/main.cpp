#include "Span.hpp"

int main()
{
    try
    {
        Span test1 = Span(6);
        test1.addNumber(-3);
        test1.addNumber(0);
        test1.addNumber(-1);
        test1.addNumber(42);
        test1.addNumber(3);
        test1.addNumber(0);
        test1.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    
    return (0);
}