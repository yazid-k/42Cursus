#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string n, int gr) : name(n)
{
	if (gr < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (gr > 150)
		throw(Bureaucrat::GradeTooLowException());
	grade = gr;
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &toCopy)
{
	grade = toCopy.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	(*this) = toCopy;
}

Bureaucrat::~Bureaucrat(void)
{
}

const std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int					Bureaucrat::getGrade(void) const
{
	return (grade);
}

void				Bureaucrat::increment(void)
{
	if (grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		grade--;
}

void				Bureaucrat::decrement(void)
{
	if (grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		grade++;
}

std::ostream	&operator << (std::ostream &output, const Bureaucrat &bc)
{
	output << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (output);
}

void				Bureaucrat::signForm(AForm &f)
{
	bool	exceptionCaught = true;

	try
	{
		f.beSigned(*this);
		exceptionCaught = false;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
	if (!exceptionCaught)
		std::cout << name << " signed " << f.getName() << std::endl;
}

void				Bureaucrat::executeForm(AForm const & form)
{
	bool	exceptionCaught = true;

	try
	{
		form.execute(*this);
		exceptionCaught = false;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	if (!exceptionCaught)
		std::cout << name << " executed " << form.getName() << std::endl;
}
