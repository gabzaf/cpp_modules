#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(const Span &other)
{
	_N = other._N;
	_nbrs = other._nbrs;
}

Span	&Span::operator=(const Span &other)
{
	if (&other != this)
	{
		_N = other._N;
		_nbrs.clear();
		for (size_t i = 0; i < other._nbrs.size(); i++)
			_nbrs.push_back(other._nbrs[i]);
		_nbrs = other._nbrs;
	}
	return (*this);
}

Span::~Span(){}

void	Span::addNumber(int nbr)
{
	if (_nbrs.size() < _N)
		_nbrs.push_back(nbr);
	else
		throw (std::out_of_range("Error: Full Container"));
}

void	Span::insertManyNbrs(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_nbrs.size() + std::distance(begin, end) > _N)
		throw (std::out_of_range("Error: Full Container"));
	_nbrs.insert(_nbrs.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_nbrs.size() < 2)
		throw (std::out_of_range("Error: Not enough numbers"));
	std::vector<int> sortedNbrs = _nbrs;
	std::sort(sortedNbrs.begin(), sortedNbrs.end());
	int minDist = sortedNbrs[1] - sortedNbrs[0];
	for (size_t i = 1; i < sortedNbrs.size() - 1; ++i)
	{
		if ((sortedNbrs[i + 1] - sortedNbrs[i]) < minDist)
			minDist = sortedNbrs[i + 1] - sortedNbrs[i];
	}
	return (minDist);
}

int	Span::longestSpan()
{
	if (_nbrs.size() < 2)
		throw (std::out_of_range("Error: Not enough numbers"));
	int minNbr = *std::min_element(_nbrs.begin(), _nbrs.end());
	int maxNbr = *std::max_element(_nbrs.begin(), _nbrs.end());
	return (abs(maxNbr - minNbr));
}

void Span::printNbrs()
{
    std::vector<int>::iterator it = this->_nbrs.begin();
    if (it == this->_nbrs.end())
    {
        std::cout << "Empty array" << std::endl;
	return ;
    }
    std::vector<int>::iterator last = this->_nbrs.end();
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
