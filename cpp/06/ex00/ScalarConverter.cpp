#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &toCopy)
{
	this->input = toCopy.input;
	return (*this);
}

ScalarConverter::ScalarConverter(char *input)
{
	this->input = input;
}


ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
	(*this) = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{
}

t_type	ScalarConverter::getType(void)
{
	return (type);
}

bool	ScalarConverter::isChar(void)
{
	return (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]));
}

bool	ScalarConverter::isInt(void)
{
	int	i = 0;

	if (input[i] && input[i] == '-')
		i++;
	while (i < (int)input.length())
	{
		if (!isdigit(input[i++]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(void)
{
	int	i = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (std::count(input.begin(), input.end(), '.') != 1)
		return (false);
	if (input[i] && input[i] == '-')
		i++;
	while (i < (int)input.length() - 1)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (false);
		i++;
	}
	return (input[i] == 'f');
}

bool	ScalarConverter::isDouble(void)
{
	int	i = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	if (std::count(input.begin(), input.end(), '.') != 1)
		return (false);
	if (input[i] && input[i] == '-')
		i++;
	while (i < (int)input.length())
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (false);
		i++;
	}
	return (true);
}

void	ScalarConverter::setType(void)
{
	if (isChar())
		type = CHAR;
	else if (isInt())
		type = INT;
	else if (isFloat())
		type = FLOAT;
	else if (isDouble())
		type = DOUBLE;
	else
		type = NONE;
}

void	ScalarConverter::convertChar(void)
{
	bool	exception = false;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: ";
	try
	{
		i = static_cast<int>(c);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << i << std::endl;
	exception = false;
	std::cout << "float: ";
	try
	{
		f = static_cast<float>(c);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << f << ".0f" << std::endl;
	exception = false;
	std::cout << "double: ";
	try
	{
		d = static_cast<double>(c);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << d << ".0" << std::endl;
}

void	ScalarConverter::convertInt(void)
{
	bool	exception = false;

	std::cout << "char: ";
	try
	{
		c = static_cast<char>(i);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		if (isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	exception = false;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: ";
	try
	{
		f = static_cast<float>(i);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		std::cout << f;
		if (f - (float)i == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	exception = false;
	std::cout << "double: ";
	try
	{
		d = static_cast<double>(i);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		std::cout << d;
		if (d - i == 0)
			std::cout << ".0" << std::endl;
	}
}

void	ScalarConverter::convertFloat(void)
{
	bool	exception = false;

	std::cout << "char: ";
	try
	{
		c = static_cast<char>(f);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		if (isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	exception = false;
	std::cout << "int: ";
	try
	{
		i = static_cast<int>(f);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << i << std::endl;
	exception = false;
	std::cout << "float: " << f;
	if (f - i == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: ";
	try
	{
		d = static_cast<double>(f);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << d << std::endl;
}

void	ScalarConverter::convertDouble(void)
{
	bool	exception = false;

	std::cout << "char: ";
	try
	{
		c = static_cast<char>(d);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		if (isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	exception = false;
	std::cout << "int: ";
	try
	{
		i = static_cast<int>(d);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
		std::cout << i << std::endl;
	exception = false;
	std::cout << "float: ";
	try
	{
		f = static_cast<float>(d);
	}
	catch(const std::exception& e)
	{
		exception = true;
		std::cout << "impossible" << std::endl;
	}
	if (!exception)
	{
		std::cout << f;
		if (f - i == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	std::cout << "double: " << d;
	if (d - i == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(void)
{
	if (type == NONE)
		std::cout << "Type unknown" << std::endl;
	if (input == "-inff" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	if (input == "nanf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	switch (type)
	{
	case CHAR:
		c = static_cast<char>(input[0]);
		convertChar();
		break;
	case INT:
		i = atoi(input.c_str());
		convertInt();
		break;
	case FLOAT:
		f = static_cast<float>(atof(input.c_str()));
		convertFloat();
		break;
	case DOUBLE:
		d = atof(input.c_str());
		convertDouble();
		break;
	case NONE:
		break;
	}
}
