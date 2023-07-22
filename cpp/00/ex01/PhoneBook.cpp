#include "PhoneBook.hpp"
#include <algorithm>

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void	PhoneBook::add()
{
	static int	i = 0;
	std::string	input[5];
	std::cout << "\t\tCONTACT INFO" << std::endl;
	std::cout << "First name : ";
	std::cin >> input[0];
	while (input[0].empty())
	{
		std::cout << "Input is empty" <<std::endl;
		std::cout << "First name : ";
		std::cin >> input[0];
	}
	std::cout << "Last name : ";
	std::cin >> input[1];
	while (input[1].empty())
	{
		std::cout << "Input is empty" <<std::endl;
		std::cout << "Last name : ";
		std::cin >> input[1];
	}
	std::cout << "Nickname : ";
	std::cin >> input[2];
	while (input[2].empty())
	{
		std::cout << "Input is empty" <<std::endl;
		std::cout << "Nick name : ";
		std::cin >> input[2];
	}
	std::cout << "Number : ";
	std::cin >> input[3];
	while (input[3].empty())
	{
		std::cout << "Input is empty" <<std::endl;
		std::cout << "Number : ";
		std::cin >> input[3];
	}
	std::cout << "Darkest secret : ";
	std::cin >> input[4];
	while (input[4].empty())
	{
		std::cout << "Input is empty" <<std::endl;
		std::cout << "Darkest secret : ";
		std::cin >> input[4];
	}
	Contact c(input);
	contacts[i++ % 8] = c;
}

void	PhoneBook::search()
{
	std::string	input;

	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "         " << i + 1 << "|";
		contacts[i].displayMenu();
	}
	std::cout << "Select contact index : ";
	std::cin >> input;
	while (input.length() != 1 || !isdigit(input[0]) || stoi(input) < 1 || stoi(input) > 8)
	{
		std::cout << "Invalid index" << std::endl;
		std::cout << "Select contact index : ";
		std::cin >> input;
	}
	contacts[stoi(input) - 1].displayContact();
}
