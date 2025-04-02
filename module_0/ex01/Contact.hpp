

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;
	
	public:
		void	add(std::string f_n, std::string nn, std::string p_n, std::string d_s);
		void	search();
		//void	exit();

};

#endif
