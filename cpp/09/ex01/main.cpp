#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Usage : ./RPN \"<expression>\"" << std::endl;
	RPN rpn(av[1]);
	return (0);
}
