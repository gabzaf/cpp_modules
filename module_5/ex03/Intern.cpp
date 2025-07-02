#include "Intern.hpp"

Intern::Intern()
{
    _formTypes["shrubbery creation"] = &Intern::createShrubberyCreationForm;
    _formTypes["robotomy request"] = &Intern::createRobotomyRequestForm;
    _formTypes["presidential pardon"] = &Intern::createPresidentialPardonForm;
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this != &other)
        _formTypes = other._formTypes;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm   *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::map<std::string, FormCreationFunction>::iterator i = _formTypes.find(formName);

    if (i != _formTypes.end())
    {
        std::cout << "Intern creates " << formName << std::endl;
        return (this->*(i->second))(target);
    }
    throw FormNotFoundException();
}

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