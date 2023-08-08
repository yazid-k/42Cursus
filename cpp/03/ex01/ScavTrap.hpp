#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	/*attr*/
public:
	ScavTrap(void);
	ScavTrap(std::string str);
	ScavTrap(const ScavTrap &toCopy);
	ScavTrap	&operator = (const ScavTrap &toCopy);
	~ScavTrap(void);

	void		guardGate(void);
};

#endif
