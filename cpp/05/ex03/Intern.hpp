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

	AForm	*makeForm(std::string form, std::string target);
};

#endif
