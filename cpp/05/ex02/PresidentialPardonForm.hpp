#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string tar);
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm	&operator = (const PresidentialPardonForm &toCopy);
	~PresidentialPardonForm(void);

	void	doStuff(void) const;
};

#endif
