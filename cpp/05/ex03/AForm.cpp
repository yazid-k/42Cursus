#include "AForm.hpp"

AForm::AForm(void) : name(""), sign(false), toSign(1), toExec(1)
{
}

AForm::AForm(std::string n, bool s, int toS, int toE) : name(n), sign(s), toSign(toS), toExec(toE)
{
	if (toS < 1 || toE < 1)
		throw(AForm::GradeTooHighException());
	if (toS > 150 || toE > 150)
		throw(AForm::GradeTooLowException());
}

AForm	&AForm::operator = (const AForm &toCopy)
{
	sign = toCopy.sign;
	return (*this);
}

AForm::AForm(const AForm &toCopy) : name(toCopy.name), toSign(toCopy.toSign), toExec(toCopy.toExec)
{
	(*this) = toCopy;
}

AForm::~AForm(void)
{
}

const std::string	AForm::getName(void) const
{
	return (name);
}

bool				AForm::getSign(void) const
{
	return (sign);
}

int			AForm::getToSign(void) const
{
	return (toSign);
}

int			AForm::getToExec(void) const
{
	return (toExec);
}

std::ostream	&operator << (std::ostream &output, const AForm &f)
{
	output << "AForm " << f.getName() << " :" << std::endl;
	output << "Signed : " << f.getSign() << std::endl;
	output << "Required grade to sign : " << f.getToSign() << std::endl;
	output << "Required grade to exec : " << f.getToExec();
	return (output);
}

void				AForm::beSigned(const Bureaucrat br)
{
	if (sign)
		throw(AForm::FormAlreadySignedException());
	else if (br.getGrade() > toSign)
		throw(AForm::GradeTooLowException());
	else
		sign = true;
}

void				AForm::execute(Bureaucrat const & executor) const
{
	if (!sign)
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > toExec)
		throw(AForm::GradeTooLowException());
	else
		doStuff();
}
