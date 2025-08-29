
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	/*Bureaucrat				*b1 = NULL;
	PresidentialPardonForm	*f1 = NULL;

	try
	{
		b1 = new Bureaucrat("Jose", 150);
		f1 = new PresidentialPardonForm();
		b1->signForm(*f1);
        b1->executeForm(*f1);
	}
	catch (const std::exception& e)
    {
		std::cerr << e.what() << '\n';
	}
	delete b1;
	delete f1;*/
	try
	{
		Bureaucrat ney("Ney", 150);
		ShrubberyCreationForm shForm("home");
		shForm.beSigned(ney);
		shForm.execute(ney);
	}
	catch (const std::exception& e)
    {
		std::cerr << e.what() << '\n';
	}
	/*try
	{
		Bureaucrat vini("Vini", 150);
		RobotomyRequestForm robForm("Marta");
		robForm.beSigned(vini);
		robForm.execute(vini);
	}
	catch (const std::exception& e)
    {
		std::cerr << e.what() << '\n';
	}*/
	return (0);
}
