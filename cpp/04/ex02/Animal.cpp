#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(std::string str)
{
	std::cout << "AAnimal constructor" << std::endl;
	type = str;
}

AAnimal::AAnimal(const AAnimal &toCopy)
{
	std::cout << "AAnimal copy constructor" << std::endl;
	type = toCopy.type;
}

AAnimal	&AAnimal::operator = (const AAnimal &toCopy)
{
	std::cout << "AAnimal assignement operator" << std::endl;
	type = toCopy.type;
	return (*this);
}

void	AAnimal::setType(std::string str)
{
	type = str;
}

std::string	AAnimal::getType(void) const
{
	return (type);
}

void	AAnimal::makeSound(void) const
{
	if (type == "Dog")
		std::cout << "Woof" << std::endl;
	else if (type == "Cat")
		std::cout << "Meow" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor" << std::endl;
}
