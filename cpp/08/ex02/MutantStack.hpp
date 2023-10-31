#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack(void) : std::stack<T>() {};
	MutantStack(const MutantStack &toCopy) : std::stack<T>(toCopy) {};
	MutantStack	&operator = (const MutantStack &toCopy) { std::stack<T>::operator=(toCopy); return (*this); };
	~MutantStack(void){};

	iterator	begin(void) { return (std::stack<T>::c.begin()); };
	iterator	end(void) { return (std::stack<T>::c.end()); };
};

#endif
