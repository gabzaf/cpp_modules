#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    private:
        unsigned int _N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void    addNumber(int nbr);
        int     shortestSpan();
        int     longestSpan();
}