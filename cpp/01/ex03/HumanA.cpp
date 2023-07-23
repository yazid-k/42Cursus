#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : weapon(w)
{
	name = n;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
