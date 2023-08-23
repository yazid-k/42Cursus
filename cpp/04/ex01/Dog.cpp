#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
	brain = new Brain();
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	std::cout << "Dog assignement operator" << std::endl;
	(*this).Animal::operator=(toCopy);
	setBrain(toCopy.getBrain());
	return (*this);
}

Dog::Dog(const Dog &toCopy)
{
	std::cout << "Dog copy constructor" << std::endl;
	(*this) = toCopy;
}

void	Dog::setBrain(Brain *br)
{
	delete (brain);
	brain = br;
}

Brain	*Dog::getBrain(void) const
{
	return (brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor" << std::endl;
	delete (brain);
}
