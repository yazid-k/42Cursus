#include "Zombie.hpp"

int main()
{
	Zombie	*z;

	z = zombieHorde(10, "Test");
	for (size_t i = 0; i < 10; i++)
		z[i].announce();
	delete[](z);
}
