#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	(*this).Animal::operator=(toCopy);
	return (*this);
}

Dog::Dog(const Dog &toCopy)
{
	std::cout << "Dog copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
