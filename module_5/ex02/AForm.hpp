#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSigned;
		const int			_gradeExec;
	public:
		AForm();
		AForm(std::string name, int gradeSigned, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSigned() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat &obj);	
	
		virtual void	execute(Bureaucrat const &executor) const = 0;


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
	class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class FileNotOpenedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outputStream, const AForm &obj);

#endif
