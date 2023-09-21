#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal &toCopy);
	WrongAnimal	&operator = (const WrongAnimal &toCopy);
	virtual ~WrongAnimal(void);

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif
