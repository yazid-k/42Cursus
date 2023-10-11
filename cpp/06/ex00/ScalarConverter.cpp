#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : toConvert("")
{
}

ScalarConverter::ScalarConverter(char *in) : toConvert(in)
{
}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &toCopy)
{
	(void)toCopy;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy) : toConvert(toCopy.toConvert)
{
	(*this) = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::toStr(void)
{
}

void	ScalarConverter::toInt(void)
{
}

void	ScalarConverter::toFloat(void)
{

}

void	ScalarConverter::toDouble(void)
{
}

void	ScalarConverter::convert(void)
{
	toStr();
	toInt();
	toFloat();
	toDouble();
}
