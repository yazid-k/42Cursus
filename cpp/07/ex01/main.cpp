#include "Iter.h"

template <typename T> void	iter(T *a, int l, void (*f)(T))
{
	for (int i = 0; i < l; i++)
		f(a[i]);
}

template <typename T> void	f(T t)
{
	std::cout << t << std::endl;
}

int main(void)
{
	int	test[4] = {0,1,2,3};
	iter(test, 4, &f);
	return 0;
}
