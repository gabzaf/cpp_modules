
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int			rawBits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int intRawBits);
		Fixed(const float floatRawBits);
		Fixed(const Fixed &other);
		Fixed &operator = (Fixed const &other);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		int	toInt(void) const;
		float	toFloat(void) const;
		
		bool	operator>(const Fixed &rhs);
		bool	operator<(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		//pre-increment (++x)
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		//pos-decrement (x++)
		Fixed	operator++(int);
		Fixed	operator--(int);

		static	Fixed &min(Fixed &a, Fixed &b);
		static	Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif
