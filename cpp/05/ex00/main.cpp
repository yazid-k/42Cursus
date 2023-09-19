#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	a = Bureaucrat("TestA", 150);
	Bureaucrat	b = Bureaucrat("TestB", 1);

	std::cout << b << std::endl;
	b.decrement();
	std::cout << b << std::endl;
	b.increment();
	std::cout << b << std::endl;
	try
	{
		b.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b << std::endl;

	std::cout << a << std::endl;
	a.increment();
	std::cout << a << std::endl;
	a.decrement();
	std::cout << a << std::endl;
	try
	{
		a.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << a << std::endl;


	try
	{
		Bureaucrat err = Bureaucrat("TestC", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat err = Bureaucrat("TestC", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
