#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("", 72, 45), _target("default")
{ 
    //std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("", 72, 45), _target(target)
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

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
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

/*
->rand()
Purpose: Generates a pseudo-random number.

Behavior: Each call returns an integer between 0 and RAND_MAX (a constant, typically 32767).

Issue: Without seeding, rand() produces the same sequence of numbers every time the program runs.

->srand(seed)
Purpose: Seeds (initializes) the pseudo-random number generator.

Why?: To make rand() produce different sequences on different program runs.

Common Usage: srand(time(0)) seeds with the current time (ensuring different sequences per run).

Key Difference:
rand() generates numbers.

srand() controls the starting point of the sequence.*/

/*How They Work Together
srand(seed) → Sets the initial seed (like a "starting point") for the random number generator.

If you don't call srand(), rand() repeats the same sequence every run (like 1, 7, 4, 3... every time).

If you do call srand(time(0)), rand() gives different numbers each run (because time(0) changes every second).

rand() → Generates the next pseudo-random number based on the seed.

It depends on srand() for randomness.

If you use the same seed, rand() will produce the same sequence.*/