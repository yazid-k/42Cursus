#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	setHp(FragTrap::getHp());
	setEp(ScavTrap::getEp());
	setAd(FragTrap::getAd());
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &toCopy)
{
	(*this).ScavTrap::operator=(toCopy);
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy)
{
	(*this) = toCopy;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n), FragTrap(n), ScavTrap(n)
{
	_name = n;
	ClapTrap::name = n + "_clap_trap";
	setHp(FragTrap::getHp());
	setEp(ScavTrap::getEp());
	setAd(FragTrap::getAd());
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DT name : " << _name << " CT name : " << name << std::endl;
}

