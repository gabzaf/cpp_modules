#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>

class	BitcoinExchange
{
	private:
		void	parse_args(int ac, char **av);

	public:
		void	run(int ac, char **av);

	class InvalidInput : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class FileOpenError : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
