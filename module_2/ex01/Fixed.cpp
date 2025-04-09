
#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int intRawBits)
{
	std::cout << "Integer constructor called" << std::endl;
	rawBits = intRawBits * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float floatRawBits)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(floatRawBits * (float)(1 << Fixed::fractionalBits));
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

int	Fixed::toInt(void)const
{
    return (rawBits >> Fixed::fractionalBits);
}

float	Fixed::toFloat() const
{
    return ((float)this->rawBits / (float)(1 << Fixed::fractionalBits));

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
