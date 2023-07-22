#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	std::string	input;
	PhoneBook	pb;

	std::cout << "PhoneBook> ";
	std::cin >> input;
	while (input != "EXIT")
	{
		while (input != "EXIT" && input != "ADD" && input != "SEARCH")
		{
			std::cout << "PhoneBook> ";
			std::cin >> input;
		}
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		std::cout << "PhoneBook> ";
		std::cin >> input;
	}
	return (0);
}
