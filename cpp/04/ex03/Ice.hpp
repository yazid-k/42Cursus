#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &toCopy);
	Ice	&operator = (const Ice &toCopy);
	~Ice(void);

	Ice	*clone() const;
};

#endif
