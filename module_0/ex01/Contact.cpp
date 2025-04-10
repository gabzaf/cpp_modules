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

static std::string	get_clean_input(const std::string &prompt)
{
	std::string	input = "";

	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit" << std::endl;
			std::exit(0);
		}
		if (input.empty())
		{
			std::cout << "Input cannot be empty." << std::endl;
			continue;
		}
		if (input.find('\t') != std::string::npos)
		{
			continue;
		}
		return (input);
	}
}

static bool	isPhonenumberValid(const std::string &pn)
{
	size_t	startIndex = 0;
	if (!pn.empty() && pn[0] == '+')
		startIndex = 1;
	for (size_t i = startIndex; i < pn.length(); i++)
	{
		if (!std::isdigit(pn[i]))
			return (false);
	}
	return (true);
}

void	Contact::set_f_n() { this->first_name = get_clean_input("First name: "); }

void	Contact::set_l_n() { this->last_name = get_clean_input("Last name: "); }

void	Contact::set_nn() { this->nickname = get_clean_input("Nickname: "); }

void	Contact::set_p_n()
{
	std::string	input;

	while (1)
	{
		input = get_clean_input("Phone number: ");
		if (!isPhonenumberValid(input))
			continue;
		this->phone_number = input;
		break;
	}
}

void	Contact::set_d_s() { this->dark_secret = get_clean_input("Dark secret: "); }

std::string	Contact::get_f_n() { return (this->first_name); }

std::string	Contact::get_l_n() { return (this->last_name); }

std::string	Contact::get_nn() { return (this->nickname); }

std::string	Contact::get_p_n() { return (this->phone_number); }

std::string	Contact::get_d_s() { return (this->dark_secret); }
