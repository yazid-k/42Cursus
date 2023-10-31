#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "stdlib.h"

Base	*generate(void)
{
	srand(time(NULL));
	int	i = rand() % 3;
	switch (i)
	{
	case 0 :
		std::cout << "A created" << std::endl;
		return (new A());
	case 1 :
		std::cout << "B created" << std::endl;
		return (new B());
	case 2 :
		std::cout << "C created" << std::endl;
		return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
}

int main(void)
{
	Base	*toIdentify = generate();
	identify(toIdentify);
	identify(*toIdentify);
	delete (toIdentify);
}
