#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain	&Brain::operator = (const Brain &toCopy)
{
	setIdeas(toCopy.getIdeas());
	return (*this);
}

Brain::Brain(const Brain &toCopy)
{
	(*this) = toCopy;
}

std::string	*Brain::getIdeas(void) const
{
	return ((std::string *)ideas);
}

void	Brain::setIdeas(std::string *arr)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = arr[i];

}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}
