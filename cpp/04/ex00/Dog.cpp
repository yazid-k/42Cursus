#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	(*this).Animal::operator=(toCopy);

	return (*this);
}

Dog::~Dog(void)
{
}
