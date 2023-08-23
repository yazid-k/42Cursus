#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string str)
{
	std::cout << "Animal constructor" << std::endl;
	type = str;
}

Animal::Animal(const Animal &toCopy)
{
	std::cout << "Animal copy constructor" << std::endl;
	type = toCopy.type;
}

Animal	&Animal::operator = (const Animal &toCopy)
{
	std::cout << "Animal assignement operator" << std::endl;
	type = toCopy.type;
	return (*this);
}

void	Animal::setType(std::string str)
{
	type = str;
}

std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	if (type == "Dog")
		std::cout << "Woof" << std::endl;
	else if (type == "Cat")
		std::cout << "Meow" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}
