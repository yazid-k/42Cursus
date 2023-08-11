#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(std::string str);
	Animal(const Animal &toCopy);
	Animal	&operator = (const Animal &toCopy);
	~Animal(void);

	void		setType(std::string str);
	std::string	getType() const;

	void		makeSound(void) const;
};

#endif
