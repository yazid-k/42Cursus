#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	std::cout << "Dog assignement operator called" << std::endl;
	(*this).Animal::operator=(toCopy);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}
