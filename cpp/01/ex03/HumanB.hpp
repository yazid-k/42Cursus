#include "Weapon.hpp"
#ifndef HUMANB_HPP
#define HUMANB_HPP
class HumanB
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	void	attack();
	void	setWeapon(Weapon &w);
	HumanB(std::string n);
	~HumanB();
};
#endif
