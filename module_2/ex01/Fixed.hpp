
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
		
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif
