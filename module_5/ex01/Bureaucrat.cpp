#include "Bureaucrat.hpp"
#include "Form.hpp"

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

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

int				Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void			Bureaucrat::incrementGrade()
{
	std::cout << _name << " is incrementing his grade from " << _grade << std::endl;
	if (_grade - 1 < 1)
         	throw GradeTooHighException();
	this->_grade--;
	std::cout << _name << " now has grade " << _grade << std::endl;
}

void			Bureaucrat::decrementGrade()
{
	std::cout << _name << " is decrementing his grade from " << _grade << std::endl;
	if (_grade + 1 > 150)
        	throw GradeTooLowException();
	this->_grade++;
	std::cout << _name << " now has grade " << _grade << std::endl;
}

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
};

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void			Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << "Form " << form.getName() << " already signed!" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
		return ;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because his grade " << getGrade() << " is too low." << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl; 
}
