#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			toSign;
	const int			toExec;

public:
	Form(void);
	Form(std::string n, bool s, int toS, int toE);
	Form(const Form &toCopy);
	Form	&operator = (const Form &toCopy);
	~Form(void);

	const std::string	getName(void) const;
	bool				getSign(void) const;
	int					getToSign(void) const;
	int					getToExec(void) const;

	void				beSigned(const Bureaucrat br);

	class GradeTooHighException : public std::exception
	{
	public :
		const char * what () const throw ()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public :
		const char * what () const throw ()
		{
			return ("Grade too low");
		}
	};
	class FormAlreadySignedException : public std::exception
	{
	public :
		const char * what () const throw ()
		{
			return ("Form already signed");
		}
	};
};

std::ostream	&operator << (std::ostream &output, const Form &f);

#endif
