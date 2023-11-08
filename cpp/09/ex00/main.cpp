#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
	if (!parseFile(ac))
		return (1);
	std::ifstream	input;
	input.open(av[1], std::ios::in);
	if (!input)
	{
		std::cout << "Error opening input file" << std::endl;
		return (1);
	}
	input.close();
	BitcoinExchange	btc(av[1]);
	return 0;
}
