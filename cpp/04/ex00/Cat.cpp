#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	(*this).Animal::operator=(toCopy);
	return (*this);
}

Cat::Cat(const Cat &toCopy)
{
	std::cout << "Cat copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
