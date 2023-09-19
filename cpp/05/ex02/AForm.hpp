#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	name;
	bool				sign;
	const int			toSign;
	const int			toExec;

public:
	AForm(void);
	AForm(std::string n, bool s, int toS, int toE);
	AForm(const AForm &toCopy);
	AForm	&operator = (const AForm &toCopy);
	~AForm(void);

	const std::string	getName(void) const;
	bool				getSign(void) const;
	int					getToSign(void) const;
	int					getToExec(void) const;

	void				beSigned(const Bureaucrat br);
	void				execute(Bureaucrat const & executor) const;
	virtual void		doStuff(void) const = 0;


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
	class FormNotSignedException : public std::exception
	{
	public :
		const char * what () const throw ()
		{
			return ("Form not signed");
		}
	};
};

std::ostream	&operator << (std::ostream &output, const AForm &f);

#endif
