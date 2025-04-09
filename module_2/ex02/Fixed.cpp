
#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const int intRawBits)
{
	rawBits = intRawBits * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float floatRawBits)
{
    rawBits = roundf(floatRawBits * (float)(1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int	Fixed::getRawBits(void) const
{
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

bool	Fixed::operator>(const Fixed &rhs)
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs)
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs)
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs)
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs)
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs)
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs)
{
    return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
    return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
    return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
    return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void)
{
    this->rawBits++;
    return(*this);
}

Fixed	&Fixed::operator--(void)
{
    this->rawBits--;
    return(*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed	tmp(*this);

    this->rawBits++;
    return (tmp);
}

Fixed	Fixed::operator--(int)
{
    Fixed	tmp(*this);

    this->rawBits--;
    return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
