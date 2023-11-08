#include "PmergeMe.hpp"

bool	vIsSorted(std::vector<int> v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
			return (false);
	}
	return (true);
}

bool	dIsSorted(std::deque<int> d)
{
	for (size_t i = 0; i < d.size() - 1; i++)
	{
		if (d[i] > d[i + 1])
			return (false);
	}
	return (true);
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const char *str[])
{
	std::cout << "Before: ";
	for (size_t i = 1; str[i]; i++)
	{
		std::cout << str[i] << " ";
		d.push_back(atoi(str[i]));
		v.push_back(atoi(str[i]));
	}
	std::cout << std::endl;
	sortdeque();
	sortvector();
	std::cout << "After: ";
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << vtime << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : "  << ltime << " us" << std::endl;
	std::cout << "std::vector is " << (vIsSorted(v) ? "sorted" : "not sorted") << std::endl;
	std::cout << "std::deque is " << (dIsSorted(d) ? "sorted" : "not sorted") << std::endl;
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &toCopy)
{
	if (this == &toCopy)
		return (*this);
	v = toCopy.v;	std::cout << "After: ";

	d = toCopy.d;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &toCopy)
{
	(*this) = toCopy;
}

PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::printV()
{
	std::cout << "vector: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printD()
{
	std::cout << "deque: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::insertSortD(std::deque<int> &toSort)
{
	for (size_t i = 1; i < toSort.size(); i++)
	{
		int key = toSort[i];
		int j = i - 1;
		while (j >= 0 && toSort[j] > key)
		{
			toSort[j + 1] = toSort[j];
			j--;
		}
		toSort[j + 1] = key;
	}
}

void	PmergeMe::insertSortV(std::vector<int> &toSort)
{
	for (size_t i = 1; i < toSort.size(); i++)
	{
		int key = toSort[i];
		int j = i - 1;
		while (j >= 0 && toSort[j] > key)
		{
			toSort[j + 1] = toSort[j];
			j--;
		}
		toSort[j + 1] = key;
	}
}

void	PmergeMe::sortdeque()
{
	clock_t	start = clock();

	for (size_t i = 0; i < d.size() - 1; i+=2)
	{
		if (d[i] > d[i + 1])
			std::swap(d[i], d[i + 1]);
	}
	std::deque<int>	main_chain;
	for (size_t i = 1; i < d.size(); i+=2)
		main_chain.push_back(d[i]);
	insertSortD(main_chain);
	main_chain.push_front(*(std::find(d.begin(), d.end(), main_chain[0]) - 1));
	d.erase(std::find(d.begin(), d.end(), main_chain[0]));
	d.erase(std::find(d.begin(), d.end(), main_chain[1]));
	while (d.size())
	{
		if (d.size() == 1)
		{
			for (std::deque<int>::iterator i = main_chain.begin(); i != main_chain.end(); i++)
			{
				if (*i > d[0])
				{
					main_chain.insert(i, d[0]);
					d.pop_front();
					break ;
				}
			}
		}
		else
		{
			std::deque<int>::iterator it = std::find(main_chain.begin(), main_chain.end(), d[1]);
			for (std::deque<int>::iterator i = main_chain.begin(); i != it || i != main_chain.end(); i++)
			{
				if (*i > d[0])
				{
					main_chain.insert(i, d[0]);
					d.pop_front();
					d.pop_front();
					break ;
				}
			}
		}
	}
	d = main_chain;
	printD();
	clock_t	end = clock();
	ltime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0 ;
}

void	PmergeMe::sortvector()
{
	clock_t	start = clock();
	for (size_t i = 0; i < v.size() - 1; i+=2)
	{
		if (v[i] > v[i + 1])
			std::swap(v[i], v[i + 1]);
	}
	std::vector<int>	main_chain;
	for (size_t i = 1; i < v.size(); i+=2)
		main_chain.push_back(v[i]);
	insertSortV(main_chain);
	main_chain.insert(main_chain.begin(), *(std::find(v.begin(), v.end(), main_chain[0]) - 1));
	v.erase(std::find(v.begin(), v.end(), main_chain[0]));
	v.erase(std::find(v.begin(), v.end(), main_chain[1]));
	while (v.size())
	{
		if (v.size() == 1)
		{
			for (std::vector<int>::iterator i = main_chain.begin(); i != main_chain.end(); i++)
			{
				if (*i > d[0])
				{
					main_chain.insert(i, d[0]);
					v.erase(v.begin());
					break ;
				}
			}
		}
		else
		{
			std::vector<int>::iterator it = std::find(main_chain.begin(), main_chain.end(), d[1]);
			for (std::vector<int>::iterator i = main_chain.begin(); i != it || i != main_chain.end(); i++)
			{
				if (*i > d[0])
				{
					main_chain.insert(i, d[0]);
					v.erase(v.begin());
					v.erase(v.begin());
					break ;
				}
			}
		}
	}
	v = main_chain;
	clock_t	end = clock();
	vtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0 ;
}
