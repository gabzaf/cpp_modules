
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try 
	{
		Bureaucrat ney("Ney", 2);
		Form a("A", 5, 10);
		Form b("B", 1, 1);

		std::cout << ney << std::endl;
		ney.signForm(a);
		std::cout << a << std::endl;

		ney.signForm(b);
		std::cout << b << std::endl;

		ney.incrementGrade();
		ney.signForm(b);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);	
}
