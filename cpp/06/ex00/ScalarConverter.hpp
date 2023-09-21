#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
private:
	/*attr*/
public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &toCopy);
	ScalarConverter	&operator = (const ScalarConverter &toCopy);
	~ScalarConverter(void);
};

#endif
