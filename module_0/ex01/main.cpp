#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	input_handler(std::string input, PhoneBook *phonebook)
{
	if (input == "ADD" || input == "1")
		phonebook->add();
	else if (input == "SEARCH" || input == "2")
		phonebook->search();
	else if (input == "EXIT" || input == "3")
		return false;
	else
		std::cout  << std::endl << " INVALID! \n\n" << std::endl;
	return true;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		input = "";
		std::cout << "1. ADD" << std::endl << "2. SEARCH" << std::endl << "3. EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exit!" << std::endl;
			std::exit(0);
		}
		if (!input_handler(input, &phonebook))
			break;
	}
	return (0);
}
