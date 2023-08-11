#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	brain = new Brain();
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	(*this).Animal::operator=(toCopy);
	setBrain(toCopy.getBrain());
	return (*this);
}

Cat::Cat(const Cat &toCopy)
{
	(*this) = toCopy;
}

void	Cat::setBrain(Brain *br)
{
	delete (brain);
	brain = br;
}

Brain	*Cat::getBrain(void) const
{
	std::cout << "Cat destructor" << std::endl;
	return (brain);
}

Cat::~Cat(void)
{
	delete (brain);
}
