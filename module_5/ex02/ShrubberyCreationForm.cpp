#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("default")
{ std::cout << "ShrubberyCreationForm default constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("", 145, 137), _target(target)
{ std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
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
	std::cout << "ShrubberyCreationForm operator overload called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();

	std::ofstream streamFile;
	std::string fileName = _target + "_shrubbery";
	streamFile.open(fileName.c_str(), std::ios_base::out);
	streamFile.close();
}


