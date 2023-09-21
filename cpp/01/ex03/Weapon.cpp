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

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string t)
{
	type = t;
}
