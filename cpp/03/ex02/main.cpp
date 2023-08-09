#include "FragTrap.hpp"
int main()
{
	FragTrap	FT1 = FragTrap("FT1");
	FragTrap	FT2 = FragTrap(FT1);
	std::cout << FT1.getAd() << std::endl;
	std::cout << FT1.getHp() << std::endl;
	std::cout << FT1.getEp() << std::endl;
	FT1.takeDamage(10);
	std::cout << FT1.getHp() << std::endl;
	std::cout << FT2.getHp() << std::endl;
	FT2 = FT1;
	std::cout << FT2.getHp() << std::endl;
	return 0;
}
