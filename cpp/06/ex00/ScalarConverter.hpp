#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <algorithm>
#include <iostream>
#include <limits>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

class ScalarConverter
{
private:
	char		c;
	int			i;
	float		f;
	double		d;
	std::string	input;
	t_type		type;

public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &toCopy);
	ScalarConverter(char *input);
	ScalarConverter	&operator = (const ScalarConverter &toCopy);
	~ScalarConverter(void);

	bool	isChar(void);
	bool	isInt(void);
	bool	isFloat(void);
	bool	isDouble(void);

	void	setType(void);
	t_type	getType(void);

	void	convertChar(void);
	void	convertInt(void);
	void	convertFloat(void);
	void	convertDouble(void);
	void	convert(void);
	void	display(void);
};

#endif
