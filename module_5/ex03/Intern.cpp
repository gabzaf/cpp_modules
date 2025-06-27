#include "Intern.hpp"

// Define the static constant array of form entries within the Intern class
const Intern::FormEntry Intern::_formEntries[] = {
    { "presidential pardon", &Intern::createPresidentialPardonForm },
    { "robotomy request", &Intern::createRobotomyRequestForm },
    { "shrubbery creation", &Intern::createShrubberyCreationForm }
};

// Define the size of the static array
const int Intern::_numFormEntries = sizeof(Intern::_formEntries) / sizeof(Intern::FormEntry);

// Helper functions to create specific forms
AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern assignation operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (int i = 0; i < _numFormEntries; ++i)
    {
        if (formName == _formEntries[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return _formEntries[i].creator(target);
        }
    }
    std::cerr << "Error: Intern cannot create form \"" << formName << "\" because it does not exist." << std::endl;
    return NULL;
}