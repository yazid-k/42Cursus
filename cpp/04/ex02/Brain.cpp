#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain	&Brain::operator = (const Brain &toCopy)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	setIdeas(toCopy.getIdeas());
	return (*this);
}

Brain::Brain(const Brain &toCopy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	(*this) = toCopy;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void		Brain::setIdeas(std::string *arr)
{
	int	i = -1;
	while (++i < 100)
		ideas[i] = arr[i];
}

std::string	*Brain::getIdeas(void) const
{
	return ((std::string *)ideas);
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}
