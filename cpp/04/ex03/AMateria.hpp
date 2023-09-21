#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	const std::string	type;
public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &toCopy);
	AMateria	&operator = (const AMateria &toCopy);
	virtual ~AMateria(void);

	std::string const	&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
