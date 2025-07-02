#include "Bureaucrat.hpp"

int	main()
{
	std::cout << std::endl << " --- Test -> Instantiating Bureaucrat with impossible grade ( > 150) --- " << std::endl << std::endl;
	try
	{
		Bureaucrat a("Rony", 155);
		std::cout << a << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &b)
	{
		std::cout<< "Exception caught - "<< b.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &b)
	{
 		std::cout<< "Exception caught - "<< b.what() << std::endl;
	}
	std::cout << std::endl << " --- Test -> Instantiating Bureaucrat with impossible grade ( < 1) ---" << std::endl << std::endl;
	try
	{
		Bureaucrat c("Tony", 0);
		std::cout << c << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &d)
	{
		std::cout<< "Exception caught - "<< d.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &d)
	{
 		std::cout<< "Exception caught - "<< d.what() << std::endl;
	}	
	std::cout << std::endl << " --- Test -> Basic methods ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat e("Ney", 149);
		std::cout << e << std::endl;
		std::cout << e.getName() << std::endl;
		std::cout << e.getGrade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &f)
	{
		std::cout<< "Exception caught - "<< f.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &f)
	{
 		std::cout<< "Exception caught - "<< f.what() << std::endl;
	}
	std::cout << std::endl << " --- Test -> Try increment ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat g("Messi", 2);
		std::cout << g << std::endl;
 		g.incrementGrade();
		std::cout << g.getGrade() << std::endl;
		g.incrementGrade();
		std::cout << g.getGrade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &h)
	{
		std::cout << "Exception caught - " << h.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &h)
	{
		std::cout << "Exception caught - " << h.what() << std::endl;
	}
	std::cout << std::endl << " --- Test -> Try decrement ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat i("Messi", 148);
		std::cout << i << std::endl;
 		i.decrementGrade();
		std::cout << i.getGrade() << std::endl;
		i.decrementGrade();
		std::cout << i.getGrade() << std::endl;
		i.decrementGrade();
		std::cout << i.getGrade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &j)
	{
		std::cout << "Exception caught - " << j.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &j)
	{
		std::cout << "Exception caught - " << j.what() << std::endl;
	}

	Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 25);
    std::cout << "Here are two bureaucrats: " << bob << " and " << alice << std::endl;
	return (0);
}
