#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain(void);
	Brain(const Brain &toCopy);
	Brain	&operator = (const Brain &toCopy);
	~Brain(void);

	void		setIdeas(std::string *arr);
	std::string	*getIdeas(void) const;
	void		setIdea(std::string idea, int index);

};

#endif
