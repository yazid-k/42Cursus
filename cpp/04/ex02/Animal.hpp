#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal(void);
	AAnimal(std::string str);
	AAnimal(const AAnimal &toCopy);
	AAnimal	&operator = (const AAnimal &toCopy);
	virtual ~AAnimal(void) = 0;


	void		setType(std::string str);
	std::string	getType() const;

	void		makeSound(void) const;
};

#endif
