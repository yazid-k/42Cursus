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
	~Fixed();
	Fixed	&operator = (const Fixed &obj);
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};


#endif
