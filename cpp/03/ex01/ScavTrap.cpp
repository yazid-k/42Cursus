#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	setAd(20);
	setHp(100);
	setEp(50);
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	setAd(20);
	setHp(100);
	setEp(50);
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &toCopy)
{
	(*this).ClapTrap::operator=(toCopy);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destuctor called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string target)
{
	if (isDead())
	{
		std::cout << "ScavTrap " << getName() << " cant't attack." << std::endl;
		return ;
	}
	if (!hasEnergy())
		return ;
	setEp(getEp() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAd() << " points of damage !" << std::endl;
}
