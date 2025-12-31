#include "BitcoinExchange.hpp"

void	BitcoinExchange::run(int ac, char **av)
{
	try
	{
		parse_args(ac, av);
		// continue program logic here
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::parse_args(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		throw (InvalidInput());
}


const char *BitcoinExchange::InvalidInput::what() const throw()
{
    return ("Error: bad input.");
}
