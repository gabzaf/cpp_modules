#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->dark_secret = "";
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
		if (!input.empty())
		{
			this->first_name = input;
			break ;
		}
		std::cout << "Enter a name: " << std::endl;
	}
}

void	Contact::set_l_n()
{
	std::string	input = "";

	while (1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
		if (!input.empty())
		{
			this->last_name = input;
			break ;
		}
		std::cout << "Enter a last name: " << std::endl;
	}
}

void	Contact::set_nn()
{
	std::string	input = "";

	while (1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
		if (!input.empty())
		{
			this->nickname = input;
			break ;
		}
		std::cout << "Enter a nickname: " << std::endl;
	}
}

void	Contact::set_p_n()
{
	std::string	input = "";

	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
		if (!input.empty())
		{
			this->phone_number = input;
			break ;
		}
		std::cout << "Enter a phone number: " << std::endl;
	}
}

void	Contact::set_d_s()
{
	std::string	input = "";

	while (1)
	{
		std::cout << "Dark Secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
		if (!input.empty())
		{
			this->dark_secret = input;
			break ;
		}
		std::cout << "Enter a nickname: " << std::endl;
	}
}

std::string	Contact::get_f_n()
{
	return (this->first_name);
}

std::string	Contact::get_l_n()
{
	return (this->last_name);
}

std::string	Contact::get_nn()
{
	return (this->nickname);
}

std::string	Contact::get_p_n()
{
	return (this->phone_number);
}

std::string	Contact::get_d_s()
{
	return (this->dark_secret);
}
