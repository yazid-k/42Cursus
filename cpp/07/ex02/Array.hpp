#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>


template <typename T>
class Array
{
private:
	T				*arr;
	unsigned int	n;
public:
	Array(void) : arr(new T[0]), n(0) {};
	Array(unsigned int i) : arr(new T[i]), n(i) {};
	Array	&operator = (const Array &toCopy)
	{
		if (arr)
			delete[] arr;
		arr = new T[toCopy.n];
		for (size_t i = 0; i < toCopy.n; i++)
			arr[i] = toCopy[i];
		n = toCopy.n;
		return (*this);
	}
	Array(const Array &toCopy) : arr(new T[toCopy.n]), n(toCopy.n)
	{
		for (size_t i = 0; i < n; i++)
			arr[i] = toCopy[i];
	}
	~Array(void)
	{
		if (arr)
			delete[] arr;
	}
	T	&operator [] (unsigned int index) const
	{
		if (index >= n)
			throw std::out_of_range("Out of range");
		return (arr[index]);
	}
	unsigned int	size(void)
	{
		return (n);
	}
};

#endif
