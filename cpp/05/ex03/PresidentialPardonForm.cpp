#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", false, 25, 5), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string tar) : AForm("PresidentialPardonForm", false, 25, 5), target(tar)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &toCopy)
{
	target = toCopy.target;
	sign = toCopy.sign;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy)
{
	(*this) = toCopy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::doStuff(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
