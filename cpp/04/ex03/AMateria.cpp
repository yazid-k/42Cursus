#include "AMateria.hpp"

AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria	&AMateria::operator = (const AMateria &toCopy)
{
	(void)toCopy;
	return(*this);
}

AMateria::AMateria(const AMateria &toCopy) : type(toCopy.type)
{
	(*this) = toCopy;
}

AMateria::~AMateria(void)
{
}

std::string const	&AMateria::getType() const
{
	return (type);
}

AMateria	*AMateria::clone() const
{
	return ((AMateria *)this);
}

void		AMateria::use(ICharacter& target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
