#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = name;
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &toCopy)
{
	std::cout << "WrongAnimal copy assignement operator called" << std::endl;
	type = toCopy.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	std::cout << "WrongAnimal copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong sound" << std::endl;
}
