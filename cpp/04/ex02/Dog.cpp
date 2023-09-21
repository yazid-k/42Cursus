#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	br = new Brain();
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	(*this).AAnimal::operator=(toCopy);
	br = new Brain(*(toCopy.getBrain()));
	return (*this);
}

Dog::Dog(const Dog &toCopy)
{
	std::cout << "Dog copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

Dog::~Dog(void)
{
	delete(br);
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (br);
}
