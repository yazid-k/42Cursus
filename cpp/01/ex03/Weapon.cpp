#include "Weapon.hpp"


Weapon::Weapon()
{
}

Weapon::Weapon(std::string t)
{
	type = t;
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string t)
{
	type = t;
}
