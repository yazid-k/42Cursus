#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat br = Bureaucrat("Test1", 20);

	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	br.signForm(*rrf);
	br.executeForm(*rrf);

	delete (rrf);
}
