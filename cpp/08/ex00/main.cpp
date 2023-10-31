#include "easyfind.h"
#include <list>
#include <vector>
template <typename T>
int	easyfind(T cont, int i)
{
	typename T::iterator it;
	for (it = cont.begin(); it != cont.end() ; it++)
	{
		if (*it == i)
			return (*it);
	}
	throw std::runtime_error("Element not found");
}

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try
	{
		int result = easyfind(lst, 10);
		std::cout << "Element found in list : " << result << std::endl;
		result = easyfind(vec, 2);
		std::cout << "Element found in vector : " << result << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}


