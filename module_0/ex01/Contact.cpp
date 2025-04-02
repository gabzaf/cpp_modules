#include "Contact.hpp"

void	Contact::add(std::string f_n, std::string nn, std::string p_n, std::string d_s)
{
	first_name = f_n;
	nickname = nn;
	phone_number = p_n;
	dark_secret = d_s;
}

void	Contact::search()
{
	std::cout << first_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << dark_secret << std::endl;
}

