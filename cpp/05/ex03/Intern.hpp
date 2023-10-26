#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &toCopy);
	Intern	&operator = (const Intern &toCopy);
	~Intern(void);

	AForm	*ppf(std::string target);
	AForm	*scf(std::string target);
	AForm	*rrf(std::string target);
	AForm	*makeForm(std::string form, std::string target);
};

#endif
