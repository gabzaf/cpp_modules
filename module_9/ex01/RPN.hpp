#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <limits>
#include <cstdlib>

class	RPN
{
	private:
		std::stack<long>	_stack;
		void			parseCharacters(std::string &input);
		bool			parseToken(const std::string &token);
	
	public:
		RPN();
        	RPN(const RPN &other);
		RPN &operator=(const RPN &src);
		~RPN();

		void	parseInput(std::string &input);
		long	operation(long nbr1, long nbr2, char op);
};
