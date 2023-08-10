#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private:
	/*attr*/
public:
	Dog(void);
	Dog(const Dog &toCopy);
	Dog	&operator = (const Dog &toCopy);
	~Dog(void);
};

#endif
