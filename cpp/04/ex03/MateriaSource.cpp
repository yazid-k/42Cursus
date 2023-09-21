#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &toCopy)
{
	(void)toCopy;
	for (size_t i = 0; i < 4; i++)
		materias[i] = toCopy.materias[i];
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &toCopy)
{
	(*this) = toCopy;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete (materias[i]);
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[3 - i] && materias[3 - i]->getType() == type)
			return (materias[3 - i]);
	}
	return (0);
}


