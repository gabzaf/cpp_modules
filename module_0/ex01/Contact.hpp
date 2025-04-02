#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;

	public:
		Contact();
		~Contact();
		void		set_f_n();
		void		set_l_n();
		void		set_nn();
		void		set_p_n();
		void		set_d_s();
		std::string	get_f_n();	
		std::string	get_l_n();
		std::string	get_nn();
		std::string	get_p_n();
		std::string	get_d_s();
};
#endif
