#include <iostream>

int main(int ac, char const *av[])
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	(void)av;
	return 0;
}
