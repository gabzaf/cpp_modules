#include "Form.hpp"

Form::Form() : _name(), _isSigned(false), _gradeSigned(150), _gradeExec(150) 
{ 
	//std::cout << "Form default constructor called" << std::endl; 
}

Form::Form(std::string name, int gradeSigned, int gradeExec) : _name(name), _isSigned(false), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
	//std::cout << "Form args constructor called" << std::endl;
	if (gradeSigned < 1 || gradeExec < 1)
		throw GradeTooLowException();
	if (gradeSigned > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(false), _gradeSigned(other._gradeSigned), _gradeExec(other._gradeExec)
{
	//std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form		&Form::operator=(const Form &other)
{
	//std::cout << "Form assignment operator overload called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

std::string		Form::getName() const { return (this->_name); }

bool			Form::getIsSigned() const { return (this->_isSigned); }

int				Form::getGradeSigned() const { return (this->_gradeSigned); }

int				Form::getGradeExec() const { return (this->_gradeExec); }

void			Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > (this->_gradeSigned))
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

const char		*Form::GradeTooLowException::what() const throw() { return ("Grade's too low!"); };

const char		*Form::GradeTooHighException::what() const throw() { return ("Grade's too high!"); };

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << "Form " << obj.getName() << " requires grade " << obj.getGradeSigned() << " to sign, grade " << obj.getGradeExec() << " to execute, signed: " << (obj.getIsSigned() ? "signed" : "not signed");
	return (os);
}
