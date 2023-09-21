#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &toCopy)
{
	(*this) = toCopy;
}

Ice	&Ice::operator = (const Ice &toCopy)
{
	(*this).AMateria::operator=(toCopy);
	return (*this);
}

Ice::~Ice(void)
{
}

Ice	*Ice::clone() const
{
	return (new Ice(*this));
}
