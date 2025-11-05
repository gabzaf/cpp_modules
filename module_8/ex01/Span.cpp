#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(const Span &other){(void)other;}

Span &Span::operator=(const Span &other)
{
    (void)other;
    //testar
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int nbr)
{
    if (this->_nbrs.size() < this->_N)
        _nbrs.push_back(nbr);
    else
        throw (std::out_of_range("Error: Full Container"));
}

int Span::shortestSpan()
{
    if (this->_nbrs.size() < 2)
        throw (std::out_of_range("Error: Not enough numbers"));
    std::list<int> sortedNbrs = this->_nbrs;
    sortedNbrs.sort();

    for (std::list<int>::iterator it = sortedNbrs.begin(); it != sortedNbrs.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    return (0);
}