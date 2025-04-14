
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called." << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator overload called." << std::endl;
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

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "WoofWoof" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}

