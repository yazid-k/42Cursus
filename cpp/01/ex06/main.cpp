#include "Harl.hpp"
#include <iostream>

int main(int argc, const char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
		return (1);
	level = argv[1];
	harl.complain(level);
	return 0;
}
