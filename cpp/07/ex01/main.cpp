#include "Iter.h"

template <typename T> void	iter(T *a, int l, void (*f)(T))
{
	for (int i = 0; i < l && a[i]; i++)
		f(a[i]);
}

void	f(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int	test[7] = {0,1,2,3};
	iter(test, 5, &f);
	return 0;
}
