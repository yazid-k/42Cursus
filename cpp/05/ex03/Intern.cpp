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

AForm	*Intern::ppf(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::scf(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::rrf(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	forms[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	AForm		*(Intern::*f[3])(std::string) = {&Intern::ppf, &Intern::scf, &Intern::rrf};

	for (size_t i = 0; i < 4; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			return ((this->*f[i])(target));
		}
	}
	std::cout << "Form error" << std::endl;
	return (NULL);
}
