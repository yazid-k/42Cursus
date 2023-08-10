#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
private:
	/*attr*/
public:
	Cat(void);
	Cat(const Cat &toCopy);
	Cat	&operator = (const Cat &toCopy);
	~Cat(void);
};

#endif
