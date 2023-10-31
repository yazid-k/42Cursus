#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	ScalarConverter	converter(argv[1]);
	converter.setType();
	converter.convert();
	return (0);
}
