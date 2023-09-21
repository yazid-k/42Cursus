#include "Character.hpp"

Character::Character(void)
{
	for (size_t i = 0; i < 4; i++)
		inv[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < 4; i++)
		inv[i] = NULL;
}

Character::Character(const Character &toCopy) : name(toCopy.name)
{
	(*this) = toCopy;
}

Character	&Character::operator = (const Character &toCopy)
{
	for (size_t i = 0; i < 4; i++)
		inv[i] = toCopy.inv[i];
	return (*this);
}

Character::~Character(void)
{
}

std::string	const & Character::getName() const
{
	return (name);
}

void		Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			inv[i] = m;
			return ;
		}
	}
}

void		Character::unequip(int idx)
{
	inv[idx] = NULL;
}

void		Character::use(int idx, ICharacter& target)
{
	if (inv[idx] != NULL)
		inv[idx]->use(target);
}

