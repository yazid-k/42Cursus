#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat				br = Bureaucrat("Test1", 20);
	RobotomyRequestForm		rrf = RobotomyRequestForm("Robotomy");
	PresidentialPardonForm	ppf = PresidentialPardonForm("Convict");
	ShrubberyCreationForm	scf = ShrubberyCreationForm("Test");

	std::cout << ppf << std::endl << br << std::endl;
	br.executeForm(ppf);
	br.signForm(ppf);
	br.signForm(ppf);
	br.executeForm(ppf);
	br.executeForm(scf);
	br.signForm(scf);
	br.executeForm(scf);
}
