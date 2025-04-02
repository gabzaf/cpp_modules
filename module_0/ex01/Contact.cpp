#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	//this->last_name = "";
	//this->nickname = "";
	//this->phone_number = "";
	//this->dark_secret = "";
}

Contact::~Contact(){}


void	Contact::set_f_n()
{
	std::string	input = "";

	while (1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
	}
}

std::string	Contact::get_f_n()
{
	return (this->first_name);
}
