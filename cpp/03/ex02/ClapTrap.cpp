#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	hp = 10;
	ep = 10;
	ad = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str)
{
	hp = 10;
	ep = 10;
	ad = 0;
	std::cout << "Constructor called" << std::endl;
	name = str;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	ad = toCopy.ad;
	hp = toCopy.hp;
	ep = toCopy.ep;
	name = toCopy.name;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &toCopy)
{
	this->ad = toCopy.ad;
	this->hp = toCopy.hp;
	this->ep = toCopy.ep;
	this->name = toCopy.name;
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}
void	ClapTrap::setHp(int points)
{
	hp = points;
}
void	ClapTrap::setEp(int points)
{
	ep = points;
}
void	ClapTrap::setAd(int points)
{
	ad = points;
}
void	ClapTrap::setName(std::string str)
{
	name = str;
}
int	ClapTrap::getHp(void)
{
	return (hp);
}
int	ClapTrap::getEp(void)
{
	return (ep);
}
int	ClapTrap::getAd(void)
{
	return (ad);
}
std::string	ClapTrap::getName(void)
{
	return (name);
}

bool	ClapTrap::hasEnergy()
{
	if (ep <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy !" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::isDead()
{
	if (hp <= 0)
		return (true);
	return (false);
}

void	ClapTrap::attack(const std::string &target)
{
	if (isDead())
	{
		std::cout << "ClapTrap " << name << " cant't attack." << std::endl;
		return ;
	}
	if (!hasEnergy())
		return ;
	ep--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ad << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " damage !" << std::endl;
	hp -= amount;
	if (isDead())
		std::cout << "ClapTrap " << name << " died !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead())
		return ;
	if (!hasEnergy())
		return ;
	ep--;
	hp += amount;
	std::cout << "ClapTrap " << name << " heals " << amount << " hit points !" << std::endl;
}
