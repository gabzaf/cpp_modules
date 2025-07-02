#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("", 72, 45), _target("default")
{ 
    //std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("robotomy form", 72, 45), _target(target)
{ 
    //std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	*this = other;
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
	{
		AForm::operator=(other);
		*this = other;
	}
	return (*this);
	//std::cout << "RobotomyRequestForm  operator overload called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    std::srand(time(0));
    if (std::rand() % 2)
        std::cout << _target << " succesfully robotomized." << std::endl;
    else
        std::cout << _target << " failed robotomized." << std::endl;
}