#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <algorithm>
class PmergeMe
{
private:
	std::vector<int>	v;
	std::deque<int>		d;
	double				vtime, ltime;
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &toCopy);
	PmergeMe(const char *str[]);
	PmergeMe	&operator = (const PmergeMe &toCopy);
	~PmergeMe(void);

	void	sortdeque();
	void	sortvector();
	void	printV();
	void	printD();
	void	insertSortD(std::deque<int> &toSort);
	void	insertSortV(std::vector<int> &toSort);
};

#endif
