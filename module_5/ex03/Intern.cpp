#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return *this;
}

Intern::~Intern(){}

AForm   *Intern::createPresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::createRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::createShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

const char  *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found!");
};

AForm   *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string form[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *(Intern::*creatorForm[3])(const std::string &target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

    for (int i = 0; i < 3; i++)
    {
        if (formName == form[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*creatorForm[i])(target));
        }
    }
    throw FormNotFoundException();
}