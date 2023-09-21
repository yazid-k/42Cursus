#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	setAd(100);
	setHp(100);
	setEp(30);
}

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
	std::cout << "FragTrap constructor called" << std::endl;
	setAd(100);
	setHp(100);
	setEp(30);
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator = (const FragTrap &toCopy)
{
	(*this).ClapTrap::operator=(toCopy);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destuctor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Five request" << std::endl;
}
