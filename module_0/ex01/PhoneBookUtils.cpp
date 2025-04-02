#include "PhoneBook.hpp"

bool	has_digit(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			return true;
	}
	return false;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
