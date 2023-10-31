#include "Serializer.hpp"
#include <stdlib.h>

int main(void)
{
	Serializer	s;
	Data		*test = new Data();
	uintptr_t	ptr = s.serialize(test);
	Data		*new_test = s.deserialize(ptr);

	test->a = 42;
	test->b = 1337;
	std::cout << test->a << " " << test->b << std::endl;
	std::cout << test << std::endl;
	std::cout << new_test->a << " " << new_test->b << std::endl;
	std::cout << new_test << std::endl;
	delete (test);
}
