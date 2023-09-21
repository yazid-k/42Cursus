#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string name)
{
	std::cout << "AAnimal constructor called" << std::endl;
	type = name;
}

AAnimal	&AAnimal::operator = (const AAnimal &toCopy)
{
	std::cout << "AAnimal copy assignement operator called" << std::endl;
	type = toCopy.type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal &toCopy)
{
	std::cout << "AAnimal copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (type);
}

void		AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound" << std::endl;
}
