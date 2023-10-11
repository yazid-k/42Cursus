#include "Iter.h"

template <typename T> void	iter(T *a, int l, void (*f)(T))
{
	for (int i = 0; i < l; i++)
		f(a[i]);
}

void	f1(int i)
{
	std::cout << i << std::endl;
}

void	f2(char c)
{
	std::cout << c << std::endl;
}

int main(void)
{
	int		testInt[7] = {0,1,2,3};
	char	testStr[5] = "abcd";
	iter(testInt, 5, &f1);
	iter(testStr, 4, &f2);
	return 0;
}
