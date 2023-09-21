#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal(void);
	AAnimal(std::string name);
	AAnimal(const AAnimal &toCopy);
	AAnimal	&operator = (const AAnimal &toCopy);
	virtual ~AAnimal(void) = 0;

	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

#endif
