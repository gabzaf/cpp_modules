#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_btcData = other._btcData;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) 
	{ 
		_btcData = other._btcData;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::run(int ac, char **av)
{
	try
	{
		parse_arg(ac, av);
		load_db();
		parse_input_file(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::parse_arg(int ac, char **av)
{
	if (ac != 2)
		throw (InvalidInput());
	std::string fileName = av[1];
	if (fileName.empty() || fileName.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		throw (InvalidInput());
}

void	BitcoinExchange::load_db()
{
	std::ifstream database("data.csv");
	if (!database)
		throw (FileOpenError());
	if (database.peek() == std::ifstream::traits_type::eof())
		throw (DatabaseError());

	std::string	line, date;
	double		price;
    
	std::getline(database, line); 
	while (std::getline(database, line))
	{
		std::istringstream	ss(line);
		if (std::getline(ss, date, ',') && (ss >> price))
		_btcData[date] = price;
	}
	if (_btcData.empty())
		throw (DatabaseError());
}

std::string	trim(const std::string &str)
{
	size_t	first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return ("");
	size_t	last = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(first, last - first + 1));
}

bool	parse_value(const std::string &valueStr, double &value)
{
	std::stringstream ss(valueStr);
	if (!(ss >> value))
		return (false);
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	parse_date(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

bool	BitcoinExchange::get_rate_for_date(const std::string &date, double &rate)
{
	std::map<std::string, double>::iterator	it = _btcData.lower_bound(date);
	if (it == _btcData.end() || it->first != date)
	{
		if (it == _btcData.begin())
			return (false); // no lower date available
		--it;
	}
	rate = it->second;
	return (true);
}

void	BitcoinExchange::parse_input_file(const std::string &filename)
{
	std::ifstream	input(filename.c_str());
	if (!input)
		throw FileOpenError();
	if (input.peek() == std::ifstream::traits_type::eof())
		throw (FileOpenError());

	std::string line;
	std::getline(input, line);

	while (std::getline(input, line))
	{
		size_t	sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
 		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));
		
		double	value;
		if (!parse_value(valueStr, value))
			continue ;
		if (!parse_date(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		double	rate;
		if (!get_rate_for_date(date, rate))
		{
			std::cerr << "Error: no available exchange rate for this date." << std::endl;
			continue ;
		}
		std::cout.precision(2);
		std::cout << std::fixed;
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}

const char	*BitcoinExchange::InvalidInput::what() const throw()
{
	return ("Error: bad input.");
}

const char	*BitcoinExchange::FileOpenError::what() const throw()
{
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::DatabaseError::what() const throw()
{
	return ("Error: invalid database.");
}
