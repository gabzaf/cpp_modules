#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

class Intern
{
    private:
        
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target);

        AForm *createPresidentialPardonForm(std::string const &target);
        AForm *createRobotomyRequestForm(std::string const &target);
	    AForm *createShrubberyCreationForm(std::string const &target);
};

#endif
