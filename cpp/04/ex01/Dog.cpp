#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	brain = new Brain();
}

Dog	&Dog::operator = (const Dog &toCopy)
{
	(*this).Animal::operator=(toCopy);
	setBrain(toCopy.getBrain());
	return (*this);
}

Dog::Dog(const Dog &toCopy)
{
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
