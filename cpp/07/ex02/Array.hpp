#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T>


class Array
{
private:
public:
	Array(void);
	Array(const Array &toCopy);
	Array	&operator = (const Array &toCopy);
	~Array(void);
};

#endif
