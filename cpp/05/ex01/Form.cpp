#include "Form.hpp"

Form::Form(void) : name(""), sign(false), toSign(1), toExec(1)
{
}

Form::Form(std::string n, bool s, int toS, int toE) : name(n), sign(s), toSign(toS), toExec(toE)
{
	if (toS < 1 || toE < 1)
		throw(Form::GradeTooHighException());
	if (toS > 150 || toE > 150)
		throw(Form::GradeTooLowException());
}

Form	&Form::operator = (const Form &toCopy)
{
	sign = toCopy.sign;
	return (*this);
}

Form::Form(const Form &toCopy) : name(toCopy.name), toSign(toCopy.toSign), toExec(toCopy.toExec)
{
	(*this) = toCopy;
}

Form::~Form(void)
{
}

const std::string	Form::getName(void) const
{
	return (name);
}

bool				Form::getSign(void) const
{
	return (sign);
}

int			Form::getToSign(void) const
{
	return (toSign);
}

int			Form::getToExec(void) const
{
	return (toExec);
}

std::ostream	&operator << (std::ostream &output, const Form &f)
{
	output << "Form " << f.getName() << " :" << std::endl;
	output << "Signed : " << f.getSign() << std::endl;
	output << "Required grade to sign : " << f.getToSign() << std::endl;
	output << "Required grade to exec : " << f.getToExec();
	return (output);
}

void				Form::beSigned(const Bureaucrat br)
{
	if (sign)
		throw(Form::FormAlreadySignedException());
	else if (br.getGrade() > toSign)
		throw(Form::GradeTooLowException());
	else
		sign = true;
}
