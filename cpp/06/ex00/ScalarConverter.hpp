#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
private:
	const char	*toConvert;
	char		*s;
	int			i;
	float		f;
	double		d;

public:
	ScalarConverter(void);
	ScalarConverter(char * in);
	ScalarConverter(const ScalarConverter &toCopy);
	ScalarConverter	&operator = (const ScalarConverter &toCopy);
	~ScalarConverter(void);

	void	toInt(void);
	void	toFloat(void);
	void	toStr(void);
	void	toDouble(void);
	void	convert(void);
};

#endif
