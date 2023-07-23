#include "Weapon.hpp"

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
