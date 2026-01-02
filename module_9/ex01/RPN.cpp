#include "RPN.hpp"

RPN::RPN() : _stack(){}

RPN::RPN(const RPN &other) : _stack(other._stack){}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other) {_stack = other._stack;}
	return (*this);
}

RPN::~RPN(){}

bool	RPN::parseToken(const std::string &token)
{
	return (((token[0] == '+' || token[0] == '-') && token.size() > 1 && std::isdigit(token[1]))) ||
            (std::isdigit(token[0]));
}

void	RPN::parseCharacters(std::string &input)
{
	if (input.empty())
		throw (std::invalid_argument("Error: empty input."));
	for (size_t i = 0; i < input.length(); i++)
	{
		char	c = input[i];
		if (!(std::isdigit(c)) && !(std::isspace(c)) && (std::string("+-/*").find(c) == std::string::npos))
			throw (std::invalid_argument("Error: invalid input"));
	}
}

long	RPN::operation(long nbr1, long nbr2, char op)
{
	switch (op)
	{
		case '+':
			return (nbr1 + nbr2);
		case '-':
			return (nbr1 - nbr2);
		case '*':
			return (nbr1 * nbr2);
		case '/':
			if (nbr2 == 0)
				throw (std::runtime_error("Error: division by zero."));
			return (nbr1 / nbr2);
		default:
			throw (std::invalid_argument("Error: invalid operator."));
	}
}

void	RPN::parseInput(std::string &input)
{
	try
	{
		parseCharacters(input);
		std::istringstream	ss(input);
		std::string		token;
		while (ss >> token)
		{
			if (parseToken(token))
			{
				char	*end;
				long	nbr = std::strtol(token.c_str(), &end, 10);
				if (*end != '\0' || nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
					throw (std::invalid_argument("Error: invalid number."));
				_stack.push(nbr);
			}
			else if ((std::string("+-/*").find(token) != std::string::npos) && (token.size() == 1))
			{
				if (_stack.size() < 2)
					throw (std::runtime_error("Error: not enough operators."));
				long	nbr2 = _stack.top();
				_stack.pop();
				long	nbr1 = _stack.top();
				_stack.pop();
				long	result = operation(nbr1, nbr2, token[0]);
				if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
					throw (std::runtime_error("Error: result out of range."));
				_stack.push(result);
			}
			else
				throw (std::invalid_argument("Error: invalid token."));
		}
		if (_stack.size() != 1)
			throw (std::runtime_error("Error: invalid RPN expression."));
		std::cout << _stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
}
