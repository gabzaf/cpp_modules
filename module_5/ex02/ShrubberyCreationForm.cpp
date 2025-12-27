#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
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
	std::cout << "Creating file: " << fileName << std::endl;
	if (!streamFile.is_open())
		throw AForm::FileNotOpenedException();
	streamFile << "       _-_" << std::endl
           << "    /~~   ~~\\" << std::endl
           << " /~~         ~~\\" << std::endl
           << "{               }" << std::endl
           << " \\  _-     -_  /" << std::endl
           << "   ~  \\\\ //  ~" << std::endl
           << "_- -   | | _- _" << std::endl
           << "  _ -  | |   -_" << std::endl
           << "      // \\\\" << std::endl;

	streamFile.close();
	std::cout << "ShrubberyCreationForm executed by " << executor.getName() << std::endl;
}


