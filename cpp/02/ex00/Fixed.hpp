#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	fbits = 8;
public:
	Fixed();
	Fixed(const Fixed &toCopy);
	Fixed	&operator = (const Fixed &toCopy);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
	int		getBits();
};

#endif
