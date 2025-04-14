#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20){ std::cout << "ScavTrap default constructor called" << std::endl; }

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20){ std::cout << "ScavTrap constructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assignment operator overload called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " cannot attack." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap" << this->_name << " is in Gate keeper mode!" << std::endl;
}

