#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", false, 145, 137), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tar) : AForm("ShrubberyCreationForm", false, 145, 137), target(tar)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator = (const ShrubberyCreationForm &toCopy)
{
	target = toCopy.target;
	sign = toCopy.sign;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy)
{
	(*this) = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::doStuff(void) const
{
	std::ofstream	file;

	file.open(target + "_shrubbery", std::ios::out);
	if (!file)
	{
		std::cout << "Error when opening file" << std::endl;
		return ;
	}

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
}
