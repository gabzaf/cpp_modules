
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	/*{
		Bureaucrat ney("Ney", 3);
	
		//ney.signForm();

		ShrubberyCreationForm shForm("taxes");
		shForm.beSigned(ney);
		PresidentialPardonForm presForm("Halaand");
		RobotomyRequestForm robForm("Marta");

		shForm.execute(ney);
	}*/

	{
		Bureaucrat vini("Vini", 30);
		RobotomyRequestForm robForm("Marta");
		robForm.beSigned(vini);
		robForm.execute(vini);
	}
	
	return (0);
}
