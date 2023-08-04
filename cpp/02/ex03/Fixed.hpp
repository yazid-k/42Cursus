#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	fbits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &toCopy);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed(void);

	Fixed				&operator = (const Fixed &toCopy);
	bool				operator > (const Fixed &toCompare) const;
	bool				operator >= (const Fixed &toCompare) const;
	bool				operator < (const Fixed &toCompare) const;
	bool				operator <= (const Fixed &toCompare) const;
	bool				operator == (const Fixed &toCompare) const;
	bool				operator != (const Fixed &toCompare) const;
	Fixed				operator + (const Fixed &toAdd) const;
	Fixed				operator - (const Fixed &toSub) const;
	Fixed				operator * (const Fixed &toMult) const;
	Fixed				operator / (const Fixed &toDiv) const;
	Fixed				&operator ++ (void);
	Fixed				operator ++ (int);
	Fixed				&operator -- (void);
	Fixed				operator -- (int);
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					getBits(void);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream	&operator << (std::ostream &output, const Fixed &fixed);

#endif
