#include "ClapTrap.hpp"

int main()
{
	ClapTrap	ct1 = ClapTrap("CT1");
	ClapTrap	ct2 = ClapTrap("CT2");

	ct1.attack("salut");
	ct2.beRepaired(10);
	ct2.takeDamage(19);
	ct2.takeDamage(1);
	ct2.takeDamage(1000);
	return 0;
}
