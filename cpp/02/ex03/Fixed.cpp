#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int raw)
{
	value = raw;
}

int	Fixed::getBits()
{
	return (fbits);
}

Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	value = toCopy.getRawBits();
}

Fixed	&Fixed::operator = (const Fixed &toCopy)
{
	value = toCopy.getRawBits();
	return (*this);
}

std::ostream	&operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int i)
{
	value = i << fbits;
}

Fixed::Fixed(const float f)
{
	value = (int)roundf(f * (1 << fbits));
}

float	Fixed::toFloat(void) const
{
	return ((value >> fbits) + ((value % 256) / 256.));
}

int	Fixed::toInt(void) const
{
	return (value >> fbits);
}

bool Fixed::operator == (const Fixed &toCompare) const
{
	if (toFloat() == toCompare.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator < (const Fixed &toCompare) const
{
	if (toFloat() < toCompare.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed &toCompare) const
{
	if (toFloat() < toCompare.toFloat() || toFloat() == toCompare.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator > (const Fixed &toCompare) const
{
	if (toFloat() <= toCompare.toFloat())
		return (false);
	return (true);
}

bool	Fixed::operator >= (const Fixed &toCompare) const
{
	if (toFloat() < toCompare.toFloat())
		return (false);
	return (true);
}

bool Fixed::operator != (const Fixed &toCompare) const
{
	if (toFloat() == toCompare.toFloat())
		return (false);
	return (true);
}

Fixed	Fixed::operator + (const Fixed &toAdd) const
{
	return (Fixed(toFloat() + toAdd.toFloat()));
}

Fixed	Fixed::operator - (const Fixed &toSub) const
{
	return (Fixed(toFloat() - toSub.toFloat()));
}

Fixed	Fixed::operator * (const Fixed &toMult) const
{
	return (Fixed(toFloat() * toMult.toFloat()));
}

Fixed	Fixed::operator / (const Fixed &toDiv) const
{
	return (Fixed(toFloat() / toDiv.toFloat()));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

Fixed	&Fixed::operator ++ (void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator -- (void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	setRawBits(getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp = *this;
	setRawBits(getRawBits() - 1);
	return (tmp);
}
