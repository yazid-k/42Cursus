#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat	&WrongCat::operator = (const WrongCat &toCopy)
{
	std::cout << "WrongCat copy assignement operator called" << std::endl;
	(*this).WrongAnimal::operator=(toCopy);
	return (*this);
}

WrongCat::WrongCat(const WrongCat &toCopy)
{
	std::cout << "WrongCat copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}
