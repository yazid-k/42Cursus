#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*brain;
public:
	Cat(void);
	Cat(const Cat &toCopy);
	Cat	&operator = (const Cat &toCopy);
	~Cat(void);

	Brain	*getBrain(void) const;
	void	setBrain(Brain *br);
};

#endif
