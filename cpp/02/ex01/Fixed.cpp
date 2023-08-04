#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int	Fixed::getBits()
{
	return (fbits);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" <<std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" <<std::endl;
	value = toCopy.getRawBits();
}

Fixed	&Fixed::operator = (const Fixed &toCopy)
{
	std::cout << "Copy assignement operator called" <<std::endl;
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
	std::cout << "Destructor called" <<std::endl;
}

Fixed::Fixed(const int i)
{
	value = i << fbits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	value = (int)roundf(f * (1 << fbits));
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((value >> fbits) + ((value % 256) / 256.));
}
int	Fixed::toInt(void) const
{
	return (value >> fbits);
}
