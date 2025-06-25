#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("", 25, 5), _target("default")
{ std::cout << "RobotomyRequestForm default constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("", 25, 5), _target(target)
{ std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	*this = other;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
	{
		AForm::operator=(other);
		*this = other;
	}
	return (*this);
	std::cout << "RobotomyRequestForm  operator overload called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{std::cout << "RobotomyRequestForm destructor called" << std::endl;}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();

	std::ofstream streamFile;
	std::string fileName = _target + "_shrubbery";
	streamFile.open(fileName.c_str(), std::ios_base::out);

    //implement noise

	streamFile.close();
}