#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
	brain = new Brain();
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	std::cout << "Cat assignement operator" << std::endl;
	(*this).AAnimal::operator=(toCopy);
	setBrain(toCopy.getBrain());
	return (*this);
}

Cat::Cat(const Cat &toCopy)
{
	std::cout << "Cat copy constructor" << std::endl;
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
	std::cout << "Cat destructor" << std::endl;
	delete (brain);
}
