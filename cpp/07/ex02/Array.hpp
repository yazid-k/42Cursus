#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T>

class Array
{
private:
	T	*t;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &toCopy);
	Array	&operator = (const Array &toCopy);
	~Array(void);
};

#endif
