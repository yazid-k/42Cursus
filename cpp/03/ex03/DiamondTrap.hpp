#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string n);
	DiamondTrap(const DiamondTrap &toCopy);
	DiamondTrap	&operator = (const DiamondTrap &toCopy);
	~DiamondTrap(void);

	using ScavTrap::attack;
	void	whoAmI(void);
};

#endif
