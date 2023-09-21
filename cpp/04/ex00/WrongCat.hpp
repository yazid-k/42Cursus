#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
	WrongCat(void);
	WrongCat(const WrongCat &toCopy);
	WrongCat	&operator = (const WrongCat &toCopy);
	~WrongCat(void);
};

#endif
