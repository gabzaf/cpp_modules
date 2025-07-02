
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;		
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int				Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void			Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
         	throw GradeTooHighException();
	this->_grade--;
}

void			Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
        	throw GradeTooLowException();
	this->_grade++;
}

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
};

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void			Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << "Form " << form.getName() << " already signed!" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because his grade " << getGrade() << " is too low." << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl; 
}

void			Bureaucrat::executeForm(AForm &form)
{
	if (form.getIsSigned())
	{
		if (form.getGradeExec() < _grade)
			std::cout << _name << " cannot execute due to low grade." << std::endl;
		else
			std::cout << _name << " executed " << form.getName() << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << _name << " cannot execute " << form.getName() << " due to missed signature." << std::endl;
	}
}