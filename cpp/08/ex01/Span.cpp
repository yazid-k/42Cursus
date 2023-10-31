#include "Span.hpp"

Span::Span(void)
{
	size = 0;
	maxsize = 0;
}

Span::Span(unsigned int n)
{
	size = 0;
	maxsize = n;
}

Span	&Span::operator = (const Span &toCopy)
{
	if (this == &toCopy)
		return (*this);
	list = toCopy.list;
	maxsize = toCopy.maxsize;
	size = toCopy.size;
	return (*this);
}

Span::Span(const Span &toCopy)
{
	(*this) = toCopy;
}

Span::~Span(void)
{
}

unsigned int	Span::getSize(void) const
{
	return (size);
}

void	Span::printList(void)
{
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	Span::addNumber(int n)
{
	if (size == maxsize)
		throw std::runtime_error("Container is full");
	list.push_back(n);
	size++;
}

void	Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if (size + std::distance(begin, end) > maxsize)
		throw std::runtime_error("Container is full");
	list.insert(list.end(), begin, end);
	size += std::distance(begin, end);
}

int	Span::shortestSpan(void)
{
	std::list<int>::iterator	i;
	std::list<int>::iterator	j;
	std::list<int>::iterator	end;
	int							min;

	if (size <= 1)
		throw std::runtime_error("Container is empty or has only one element");
	i = list.begin();
	j = list.begin();
	end = list.end();
	min = longestSpan();
	for (; i != end; i++)
	{
		for (j = i; j != end; j++)
		{
			if (i != j && std::abs(*i - *j) < min)
				min = std::abs(*i - *j);
			if (!min)
				return (0);
		}
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (size <= 1)
		throw std::runtime_error("Container is empty or has only one element");
	return (*std::max_element(list.begin(), list.end()) - *std::min_element(list.begin(), list.end()));
}
