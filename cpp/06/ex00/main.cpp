#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ScalarConverter	sc = ScalarConverter(av[1]);
	sc.convert();
	return (0);
}
