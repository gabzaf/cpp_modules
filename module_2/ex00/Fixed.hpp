
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int			rawBits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator = (Fixed const &other);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
