#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &toCopy)
{
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
	(*this) = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{
}
