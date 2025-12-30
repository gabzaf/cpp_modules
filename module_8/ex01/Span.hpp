#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <algorithm>
#include <cstdlib>

class Span
{
	private:
		std::vector<int> _nbrs;	
		unsigned int _N;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void    addNumber(int nbr);
		void    insertManyNbrs(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int     shortestSpan();
		int     longestSpan();

		void    printNbrs();
};

#endif
