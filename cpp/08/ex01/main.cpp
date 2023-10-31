#include "Span.hpp"

int main()
{
	Span sp(20000);
	std::list<int> lst;

	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(rand() % 100000);
		lst.push_back(rand() % 100000);
	}

	std::cout << "Size: " << sp.getSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	sp.addNumber(lst.begin(), lst.end());
	std::cout << "Size: " << sp.getSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
