#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	br = new Brain();
}

Cat	&Cat::operator = (const Cat &toCopy)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	(*this).Animal::operator=(toCopy);
	br = new Brain(*(toCopy.getBrain()));
	return (*this);
}

Cat::Cat(const Cat &toCopy)
{
	std::cout << "Cat copy assignement constructor called" << std::endl;
	(*this) = toCopy;
}

Cat::~Cat(void)
{
	delete(br);
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (br);
}
