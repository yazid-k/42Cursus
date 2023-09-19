#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern	&Intern::operator = (const Intern &toCopy)
{
	(void)toCopy;
	return (*this);
}

Intern::Intern(const Intern &toCopy)
{
	(*this) = toCopy;
}

Intern::~Intern(void)
{
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	if (form == "PresidentialPardonForm")
		return (new PresidentialPardonForm(target));
	if (form == "ShrubberyCreationForm")
		return (new ShrubberyCreationForm(target));
	if (form == "RobotomyRequestForm")
		return (new RobotomyRequestForm(target));
	else
	{
		std::cout << "Form error" << std::endl;
		return (NULL);
	}
}
