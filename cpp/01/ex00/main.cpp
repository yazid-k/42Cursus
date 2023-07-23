#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Zombie on heap");
	zombie->announce();
	delete zombie;
	randomChump("Zombie on stack");
	return 0;
}
