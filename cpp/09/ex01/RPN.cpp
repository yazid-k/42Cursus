#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::string input)
{
	parseString(input);
}

RPN::RPN(const RPN &toCopy)
{
	*this = toCopy;
}

RPN	&RPN::operator = (const RPN &toCopy)
{
	if (this == &toCopy)
		return (*this);
	stack = toCopy.stack;
	return (*this);
}

RPN::~RPN(void)
{
}

bool	isOp(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (true);
	return (false);
}
bool	RPN::doOp(char c)
{
	if (stack.empty())
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	int	i = stack.top();
	stack.pop();
	switch (c)
	{
		case '+':
			stack.top() += i;
			break;
		case '-':
			stack.top() -= i;
			break;
		case '*':
			stack.top() *= i;
			break;
		case '/':
			if (!i)
			{
				std::cout << "Division by zero" << std::endl;
				return (false);
			}
			stack.top() /= i;
			break;
		case '%':
			stack.top() %= i;
			break;
	}
	return (true);
}

bool	RPN::parseString(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		while (input[i] == ' ')
			i++;
		if (!isdigit(input[i]) && !isOp(input[i]))
		{
			std::cout << "Error" << std::endl;
			return (false);
		}
		if ((isdigit(input[i]) || isOp(input[i + 1])) && input[i + 1] && !isspace(input[i + 1]))
		{
			std::cout << "Error" << std::endl;
			return (false);
		}
		if (isdigit(input[i]))
			stack.push(input[i] - '0');
		if (isOp(input[i]))
			if (!doOp(input[i]))
				return (false);
	}
	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	std::cout << stack.top() << std::endl;
	return (true);
}
