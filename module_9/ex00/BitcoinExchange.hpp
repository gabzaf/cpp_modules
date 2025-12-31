#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>

class BitcoinExchange
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
};

#endif
