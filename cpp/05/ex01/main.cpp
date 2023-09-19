#include "Form.hpp"

int main(void)
{
	try
	{
		Form err = Form("Err", true, 10, 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form err = Form("Err", true, 160, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form err = Form("Err", true, 10, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form err = Form("Err", true, 0, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat a = Bureaucrat("A", 12);
	Bureaucrat b = Bureaucrat("B", 20);
	Form f = Form("Test", false, 15, 10);

	std::cout << f << std::endl << a << std::endl << b << std::endl;
	b.signForm(f);
	a.signForm(f);
	a.signForm(f);
}
