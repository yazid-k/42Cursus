#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog(void);
	Dog(const Dog &toCopy);
	Dog	&operator = (const Dog &toCopy);
	~Dog(void);

	Brain	*getBrain(void) const;
	void	setBrain(Brain *br);
};

#endif
