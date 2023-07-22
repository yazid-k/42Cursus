#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
	Zombie	*z = new Zombie;
	z->name = name;
	return (z);
}

void	randomChump( std::string name );
