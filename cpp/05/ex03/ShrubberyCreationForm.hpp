#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string tar);
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm	&operator = (const ShrubberyCreationForm &toCopy);
	~ShrubberyCreationForm(void);

	void	doStuff(void) const;
};

#endif
