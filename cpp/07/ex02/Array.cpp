#include "Array.hpp"

Array::Array(void)
{
}

Array	&Array::operator = (const Array &toCopy)
{
	return (*this);
}

Array::Array(const Array &toCopy)
{
	(*this) = toCopy;
}

Array::~Array(void)
{
}

