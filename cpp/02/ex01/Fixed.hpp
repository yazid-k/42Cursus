#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed	&operator = (const Fixed &obj);
	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
	void	setRawBits(const int raw);
};


#endif
