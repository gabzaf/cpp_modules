
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Idea idea";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator overload called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string &Brain::getIdeas(int i) const
{
	if (i >= 0 && i < 100)
		return (_ideas[i]);
	throw std::out_of_range("Index out of bonds");
}

void Brain::setIdeas(int i, const std::string &idea)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
	else
		throw std::out_of_range("Index out of bounds.");
}
