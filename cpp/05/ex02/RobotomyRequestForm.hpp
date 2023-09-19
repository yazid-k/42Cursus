#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string tar);
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm	&operator = (const RobotomyRequestForm &toCopy);
	~RobotomyRequestForm(void);

	void	doStuff(void) const;
};

#endif
