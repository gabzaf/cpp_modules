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
    std::list<int>::iterator it1 = sortedNbrs.begin();
    std::list<int>::iterator it2 = ++sortedNbrs.begin();
    int i = *it2 - *it1;
    while (it2 != sortedNbrs.end())
    {
        if (i > *it2 - *it1)
            i = *it2 - *it1;
        it1++;
        it2++;
    }
    return (i);
}

void Span::printNbrs()
{
    std::list<int>::iterator it = this->_nbrs.begin();
    if (it == this->_nbrs.end())
        std::cout << "Empty array" << std::endl;
    std::list<int>::iterator last = this->_nbrs.end();
    std::cout << "Array" << std::endl;
    while (it != this->_nbrs.end())
    {
        std::cout << *it;
        it++;
        if (it != last)
            std::cout << ", ";
    }
    std::cout << std::endl;
}