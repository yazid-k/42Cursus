#include "DiamondTrap.hpp"
int main()
{
	DiamondTrap	dt("Test");
	DiamondTrap	dtt;

	dt.whoAmI();
	dtt = dt;
	dtt.highFivesGuys();
	return 0;
}
