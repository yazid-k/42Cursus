#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete(meta);
	delete(j);
	delete(i);
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* l = new WrongAnimal();
	k->makeSound();
	l->makeSound();
	delete(k);
	delete(l);
}
