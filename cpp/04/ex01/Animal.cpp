#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string name)
{
	std::cout << "Animal constructor called" << std::endl;
	type = name;
}

Animal	&Animal::operator = (const Animal &toCopy)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	type = toCopy.type;
	return (*this);
}

Animal::Animal(const Animal &toCopy)
{
	std::cout << "Animal copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}

void		Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
