
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	tt_ctts_obj;
		int	oldest_contact;

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
		void	contacts_printer();
		void	display_index();
};

std::string truncate(std::string str);

#endif
