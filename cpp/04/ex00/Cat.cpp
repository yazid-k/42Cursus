#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	(*this).Animal::operator=(toCopy);

	return (*this);
}

Cat::~Cat(void)
{
}
