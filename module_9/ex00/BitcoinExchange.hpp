#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>
#include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_btcData;

		void	parse_arg(int ac, char **av);
		void	load_db();
		void	parse_input_file(const std::string &filename);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	run(int ac, char **av);

	class	InvalidInput : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class	FileOpenError : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class	DatabaseError : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
