#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private :
	AMateria	*materias[4];
public :
	MateriaSource(void);
	MateriaSource(const MateriaSource &toCopy);
	MateriaSource	&operator = (const MateriaSource &toCopy);
	~MateriaSource(void);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
