#include "ScavTrap.hpp"
int main()
{
	ScavTrap	ct1 = ScavTrap("CT1");
	ScavTrap	ct2 = ScavTrap(ct1);
	std::cout << ct1.getAd() << std::endl;
	std::cout << ct1.getHp() << std::endl;
	std::cout << ct1.getEp() << std::endl;
	ct1.takeDamage(10);
	std::cout << ct1.getHp() << std::endl;
	std::cout << ct2.getHp() << std::endl;
	ct2 = ct1;
	std::cout << ct2.getHp() << std::endl;
	ct1.guardGate();
	return 0;
}
