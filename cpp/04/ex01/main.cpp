#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal	*A[100];

	for (size_t i = 0; i < 50; i++)
	{
		A[i] = new Cat();
		A[i + 50] = new Dog();
	}
	for (size_t i = 0; i < 100; i++)
		std::cout << A[i]->getType() << std::endl;
	delete [] *A;
	return (0);
}
