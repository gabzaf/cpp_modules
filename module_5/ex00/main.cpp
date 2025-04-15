#include "Bureaucrat.hpp"

int	main()
{
	std::cout << " --- Test - try decrement ---" << std::endl;
	try 
	{
		Bureaucrat a("Ney", 149);
		std::cout << a << std::endl;
		a.decrementGrade();
		a.decrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &b)
	{
		std::cout<< "Exception caught - "<< b.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &b)
	{
 		std::cout<< "Exception caught - "<< b.what() << std::endl;
	}

	std::cout << " --- Test - try increment ---" << std::endl;
	try 
	{
		Bureaucrat c("Messi", 10);
		std::cout << c << std::endl;
 		c.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception caught - " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Exception caught - " << e.what() << std::endl;
	}
	return (0);
}
