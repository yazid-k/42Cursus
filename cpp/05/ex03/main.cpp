#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	delete (rrf);
}
