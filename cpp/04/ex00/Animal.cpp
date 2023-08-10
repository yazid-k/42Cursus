#include "Animal.hpp"

Animal::Animal(void)
{
}

Animal::Animal(std::string str)
{
	type = str;
}

Animal::Animal(const Animal &toCopy)
{
	type = toCopy.type;
}

Animal	&Animal::operator = (const Animal &toCopy)
{
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
}
