#include "Zombie.hpp"

std::string	Zombie::getName(void)
{
	return (name);
}

void	Zombie::setName(std::string n)
{
	name = n;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}
