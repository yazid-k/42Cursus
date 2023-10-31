#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
class Span
{
private:
	std::list<int>	list;
	unsigned int	maxsize;
	unsigned int	size;
public:
	Span(void);
	Span(const Span &toCopy);
	Span(unsigned int n);
	Span	&operator = (const Span &toCopy);
	~Span(void);

	unsigned int	getSize(void) const;
	void			printList(void);
	void			addNumber(int n);
	void			addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
	int				shortestSpan(void);
	int				longestSpan(void);

};


#endif
