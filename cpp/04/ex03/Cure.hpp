#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &toCopy);
	Cure	&operator = (const Cure &toCopy);
	~Cure(void);

	Cure	*clone() const;
};

#endif
