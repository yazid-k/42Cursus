#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	std::cout << "Cat assignement operator called" << std::endl;
	(*this).Animal::operator=(toCopy);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}
