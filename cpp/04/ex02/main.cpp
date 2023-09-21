#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	//AAnimal *a = new AAnimal();
	AAnimal	*a = new Dog();
	Dog		*b = new Dog();

	delete (a);
	delete (b);
	return (0);
}
