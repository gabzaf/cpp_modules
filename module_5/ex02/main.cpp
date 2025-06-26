
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
		shForm.execute(ney);
	}*/

	/*{
		Bureaucrat vini("Vini", 30);
		RobotomyRequestForm robForm("Marta");
		robForm.beSigned(vini);
		robForm.execute(vini);
	}*/

	/*{
		Bureaucrat messi("Messi", 4);
		PresidentialPardonForm presForm("Halaand");
		presForm.beSigned(messi);
		presForm.execute(messi);
	}*/
	
	{
		Bureaucrat mbappe("Mbappe", 40);
		PresidentialPardonForm presForm("Halaand");
		presForm.beSigned(mbappe);
		mbappe.executeForm(presForm);
		
	}

	return (0);
}
