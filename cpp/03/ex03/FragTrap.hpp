#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
public:
	FragTrap(void);
	FragTrap(std::string str);
	FragTrap(const FragTrap &toCopy);
	FragTrap	&operator = (const FragTrap &toCopy);
	~FragTrap(void);
	void		highFivesGuys(void);
};

#endif
