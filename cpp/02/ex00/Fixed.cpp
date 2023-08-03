#include "Fixed.hpp"

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int bits)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = bits;
}

int	Fixed::getBits()
{
	return (fbits);
}

Fixed::Fixed()
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}
