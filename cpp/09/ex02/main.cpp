#include "PmergeMe.hpp"

bool	parseInt(char *str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		if (i > 8)
			return (false);
		if (i == 8 && str[0] > '2')
			return (false);
	}
	if (!str[0])
		return (false);
	if (atoi(str) < 0)
		return (false);
	return (true);
}

int main(int ac, char const *av[])
{
	if (ac == 1)
	{
		std::cout << "Usage: ./pmergeMe [number] [number] [number] ..." << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		if (!parseInt((char *)av[i]))
		{
			std::cout << "Error: invalid argument : " << av[i] << std::endl;
			return (1);
		}
	}
	PmergeMe pmergeMe(av);
	return 0;
}
