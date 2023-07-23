#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	name = n;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}
