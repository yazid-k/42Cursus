#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat				br = Bureaucrat("Test1", 20);

	PresidentialPardonForm	ppf = PresidentialPardonForm("Test2");

	std::cout << ppf << std::endl << br << std::endl;
	br.executeForm(ppf);
	br.signForm(ppf);
	br.signForm(ppf);
	br.executeForm(ppf);
}
