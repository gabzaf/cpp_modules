
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("DogaCat")
{
	std::cout << "Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Animal args constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal() { std::cout << "Animal destructor called." << std::endl; }

void	AAnimal::makeSound() const
{
	std::cout << "DogaCat sound" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
