#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &toCopy)
{
	(*this) = toCopy;
}

Cure	&Cure::operator = (const Cure &toCopy)
{
	(*this).AMateria::operator=(toCopy);
	return (*this);
}

Cure::~Cure(void)
{
}

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}
