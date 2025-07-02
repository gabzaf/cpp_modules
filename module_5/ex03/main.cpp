#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	try
	{
    	Intern joao;
    	AForm* form;

    	std::cout << std::endl << "--- Testing Valid Form Creation ---" << std::endl;

    	form = joao.makeForm("shrubbery creation", "home");
    	if (form)
    	{
    	    std::cout << "Successfully created form: " << form->getName() << std::endl;
    	    delete form;
    	}

    	std::cout << "--------------------" << std::endl;

    	form = joao.makeForm("robotomy request", "Bender");
    	if (form)
    	{
    	    std::cout << "Successfully created form: " << form->getName() << std::endl;
    	    delete form;
    	}

    	std::cout << "--------------------" << std::endl;

    	form = joao.makeForm("presidential pardon", "Zaphod");
    	if (form)
    	{
    	    std::cout << "Successfully created form: " << form->getName() << std::endl;
    	    delete form;
    	}

		std::cout << "--------------------" << std::endl;
		
		form = joao.makeForm("King pardon", "Charles");
    	if (form)
    	{
    	    std::cout << "Successfully created form: " << form->getName() << std::endl;
    	    delete form;
    	}
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
    return (0);
}