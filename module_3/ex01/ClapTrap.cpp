#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap args constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap inheritance constructor called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator overload called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap destructor called" << std::endl;}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack." << std::endl;
}

void	ClapTrap::takeDamage(int amount)
{
	if (amount < 0)
	{
		std::cout << std::endl << "Nonsense number" << std::endl << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 1)
	{
		std::cout << std::endl << "ClapTrap " << this->_name << " died" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(int amount)
{
	if (amount < 0)
	{
		std::cout << std::endl << "Nonsense number" << std::endl << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no hit points." << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " got repaired and regained " << amount << " hit points!" << std::endl;
}
