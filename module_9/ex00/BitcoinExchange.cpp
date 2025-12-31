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
	if (ac != 2)
		throw (InvalidInput());
	std::string fileName = av[1];
	if (fileName.empty() || fileName.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		throw (InvalidInput());
	std::ifstream inputFile(fileName.c_str());
	if (!inputFile || inputFile.peek() == std::ifstream::traits_type::eof())
		throw (FileOpenError());
	std::ifstream database("data.csv");
	if (!database || database.peek() == std::ifstream::traits_type::eof())
		throw (FileOpenError());
}

const char	*BitcoinExchange::InvalidInput::what() const throw()
{
	return ("Error: bad input.");
}

const char	*BitcoinExchange::FileOpenError::what() const throw()
{
	return ("Error: could not open file.");
}
