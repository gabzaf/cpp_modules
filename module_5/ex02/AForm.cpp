
#include "AForm.hpp"

AForm::AForm() : _name(), _isSigned(false), _gradeSigned(150), _gradeExec(150) { std::cout << "Form default constructor called" << std::endl; }

AForm::AForm(std::string name, int gradeSigned, int gradeExec) : _name(name), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
	this->_isSigned = false;
	std::cout << "Form args constructor called" << std::endl;
	if (gradeSigned < 1 || gradeExec < 1)
		throw GradeTooLowException();
	if (gradeSigned > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(false), _gradeSigned(other._gradeSigned), _gradeExec(other._gradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

AForm		&AForm::operator=(const AForm &other)
{
	std::cout << "Form assignment operator overload called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

AForm::~AForm() { std::cout << "Form destructor called" << std::endl; }

std::string	AForm::getName() const { return (_name); }

int		AForm::getGradeSigned() const { return (_gradeSigned); }

int		AForm::getGradeExec() const { return (_gradeExec); }

bool		AForm::getIsSigned() const { return (_isSigned); }

void		AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > _gradeSigned)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

const char	*AForm::GradeTooLowException::what() const throw() { return ("Grade's too low!"); };

const char	*AForm::GradeTooHighException::what() const throw() { return ("Grade's too high!"); };

const char	*AForm::FormNotSignedException::what() const throw() { return ("Form's not signed!"); };

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	os << "Form " << obj.getName() << " requires grade " << obj.getGradeSigned() << " to sign, grade " << obj.getGradeExec() << " to execute, signed: " << (obj.getIsSigned() ? "y" : "n");
	return (os);
}
