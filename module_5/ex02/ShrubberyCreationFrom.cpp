#include "AForm.hpp"
#include "ShrubberyCreationFrom.hpp"

ShrubberyCreationFrom::ShrubberyCreationForm() : AForm("", false, 145, 137)
{ std::cout << "ShrubberyCreationForm default constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		*this = other;
	}
	return (*this);
	std::cout << "ShrubberyCreationForm assigment operator overload called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	execute(Bureaucrat const &executor);



