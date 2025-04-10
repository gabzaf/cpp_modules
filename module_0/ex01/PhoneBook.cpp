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
	std::cout << "Contact " << contacts[oldest_contact].get_f_n() << " deleted!" << std::endl << std::endl;
	contacts[oldest_contact].set_f_n();
	contacts[oldest_contact].set_l_n();
	contacts[oldest_contact].set_nn();	
	contacts[oldest_contact].set_p_n();
	contacts[oldest_contact].set_d_s();
	std::cout << "-------------------" << std::endl;
	std::cout << " Contact added!" << std::endl;
	std::cout << "-------------------" << std::endl << std::endl;
	if (oldest_contact < 6)
		oldest_contact += 1;
	else
		oldest_contact = 0;
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

void	PhoneBook::display_index()
{
	int		i;
	size_t		j;
	std::string	str;	
	bool		is_nbr_valid;

	while (1)
	{
		std::cout << std::endl << "Enter the index to display the Contact Information" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exit!" << std::endl;
			std::exit(0);
		}
		is_nbr_valid = true;
		j = 0;
		if (str.empty())
			is_nbr_valid = false;
		while (j < (str.length()))
		{
			if (!isdigit(str[j]))
			{
				is_nbr_valid = false;
				break;
			}
			j++;
		}
		if (!is_nbr_valid)
			continue;
		i = std::atoi(str.c_str());
		if (i < 1 || i > tt_ctts_obj)
			continue;
		i -= 1;
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "  Contact for selected index  " << std::endl;
		std::cout << "------------------------------" << std::endl;
	
		std::cout << "First Name: " << this->contacts[i].get_f_n() << std::endl;
		std::cout << "Last Name: " << this->contacts[i].get_l_n() << std::endl;
		std::cout << "Nickame: " << this->contacts[i].get_nn() << std::endl;
		std::cout << "Phone number: " << this->contacts[i].get_p_n() << std::endl;
		std::cout << "Dark Secret: " << this->contacts[i].get_d_s() << std::endl;
		std::cout << std::endl;
		break;
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
	std::cout << std::endl;
	if (std::cin.eof())
	{
		std::cout << std::endl << "Exit!" << std::endl;
		std::exit(0);
	}
	display_index();
}
