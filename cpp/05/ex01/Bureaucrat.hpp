#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string n, int gr);
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat	&operator = (const Bureaucrat &toCopy);
	~Bureaucrat(void);

	const std::string	getName(void) const;
	int					getGrade(void) const;

	void				increment(void);
	void				decrement(void);
	void				signForm(Form &f);

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
};



std::ostream	&operator << (std::ostream &output, const Bureaucrat &bc);

#endif
