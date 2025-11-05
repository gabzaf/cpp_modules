#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <exception>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::list<int> _nbrs;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void    addNumber(int nbr);
        void    addManyNumbers(int begin, int end);
        int     shortestSpan();
        int     longestSpan();

        void    printNbrs();
};

#endif