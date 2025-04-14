

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called." << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator overload called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << "Miaaauu" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}
