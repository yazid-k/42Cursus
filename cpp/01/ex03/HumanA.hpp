#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon		&weapon;
	std::string	name;
public:
	void	attack();
	HumanA(std::string n, Weapon &w);
	~HumanA();
};
#endif
