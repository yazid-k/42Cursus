#include <iostream>
#include <fstream>

std::string	replace(std::string line,std::string s1, std::string s2)
{
	size_t	position;

	position = 0;
	while (position != std::string::npos)
	{
		position = line.find(s1, position);
		if (position == std::string::npos)
			break;
		line.erase(position, s1.length());
		line.insert(position, s2);
	}
	return (line);
}

int main(int ac, char const *av[])
{
	std::ifstream	read;
	std::ofstream	write;
	std::string		s1, s2;
	std::string		fileName;
	std::string		line;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	read.open(av[1], std::ios::in);
	if (!read)
	{
		std::cout << "Error when opening file " << av[1] << std::endl;
		return (0);
	}
	fileName.append(av[1]);
	fileName.append(".replace");
	write.open(fileName, std::ios::out);
	if (!write)
	{
		std::cout << "Error when creating file " << av[1] << std::endl;
		return (0);
	}
	s1 = av[2];
	s2 = av[3];
	while (read)
	{
		std::getline(read, line);
		write << replace(line, s1, s2);
		if (line != "")
			write << std::endl;
	}
	read.close();
	write.close();
	return (0);
}
