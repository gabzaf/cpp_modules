#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeSigned;
		const int		_gradeExec;
	public:
		Form();
		Form(std::string name, int gradeSigned, int gradeExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int		getGradeSigned() const;
		int		getGradeExec() const;
		void		beSigned(Bureaucrat &obj);	
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outputStream, const Form &obj);

#endif
