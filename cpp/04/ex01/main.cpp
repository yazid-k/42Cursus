#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal	*A[100];
	for (int i = 0; i < 50; i++)
	{
		A[i] = new Cat();
		A[i + 50] = new Dog();
	}
	for (int i = 0; i < 100; i++)
		delete (A[i]);
	//Deep copy test
	Dog	test = Dog();

	std::cout << test.getBrain()->getIdeas()[2] << std::endl;
	test.getBrain()->setIdea("Salut", 2);
	std::cout << test.getBrain()->getIdeas()[2] << std::endl;

	Dog copy = test;
	std::cout << copy.getBrain()->getIdeas()[2] << std::endl;

	return (0);
}
