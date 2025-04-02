#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->oldest_contact = 0;
	this->tt_ctts_obj = 0;
	std::cout << std::endl << "-------------" << std::endl;
	std::cout << "  PHONEBOOK " << std::endl;
	std::cout << "-------------" << std::endl << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "--------------------";
	std::cout << std::endl << " Exiting PhoneBook" << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;

	return ;
}

void	PhoneBook::add()
{
	if (tt_ctts_obj < 8)
	{
		contacts[tt_ctts_obj].set_f_n();
		contacts[tt_ctts_obj].set_l_n();
		contacts[tt_ctts_obj].set_nn();	
		contacts[tt_ctts_obj].set_p_n();
		contacts[tt_ctts_obj].set_d_s();
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << " Contact added!" << std::endl;
		std::cout << "-------------------" << std::endl << std::endl;
		tt_ctts_obj += 1;
		return ;
	}


}

void	PhoneBook::contacts_printer()
{
	const int	width = 10;

	std::cout << std::endl <<  "CONTACTS " << std::endl;
	std::cout << std::setw(width) << truncate("INDEX") << "|";
	std::cout << std::setw(width) << truncate("FIRST NAME") << "|";
	std::cout << std::setw(width) << truncate("LAST NAME") << "|";
	std::cout << std::setw(width) << truncate("NICKNAME") << std::endl;
	for (int i = 0; i < tt_ctts_obj; i++)
	{
		std::cout << std::setw(width) << i + 1 << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_f_n()) << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_l_n()) << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_nn()) << std::endl;
	}
}

void	PhoneBook::search()
{
	if (tt_ctts_obj == 0)
	{
		std::cout << "No contacts!" << std::endl;
		return ;
	}
	contacts_printer();
	if (std::cin.eof())
	{
		std::cout << std::endl << "Exit!" << std::endl;
		std::exit(0);
	}
}
