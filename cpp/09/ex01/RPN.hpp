#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<int>	stack;
public:
	RPN(void);
	RPN(std::string input);
	RPN(const RPN &toCopy);
	RPN	&operator = (const RPN &toCopy);
	~RPN(void);

	bool	parseString(std::string input);
	bool	doOp(char c);
};

#endif
