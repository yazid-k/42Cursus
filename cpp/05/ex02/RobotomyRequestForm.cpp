#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false, 72, 45), target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string tar) : AForm("RobotomyRequestForm", false, 72, 45), target(tar)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &toCopy)
{
	target = toCopy.target;
	sign = toCopy.sign;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy)
{
	(*this) = toCopy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::doStuff(void) const
{
	srand(time(NULL));
	if (rand() % 2)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
