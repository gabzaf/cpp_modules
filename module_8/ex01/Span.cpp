#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(const Span &other){(void)other;}

Span &Span::operator=(const Span &other)
{
    //testar
    return (*this);
}

