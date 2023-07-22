#include "Contact.hpp"

std::string	Contact::getfirstname()
{
	return (firstname);
}
std::string	Contact::getlastname()
{
	return (lastname);
}
std::string	Contact::getnickname()
{
	return (nickname);
}
std::string	Contact::getnumber()
{
	return (number);
}
std::string	Contact::getsecret()
{
	return (secret);
}
void	Contact::setfirstname(std::string fn)
{
	firstname = fn;
}
void	Contact::setlastname(std::string ln)
{
	lastname = ln;
}
void	Contact::setnickname(std::string nn)
{
	nickname = nn;
}
void	Contact::setnumber(std::string num)
{
	number = num;
}
void	Contact::setsecret(std::string s)
{
	secret = s;
}

void	Contact::displayContact()
{
	std::cout << "First name : " << getfirstname() << std::endl;
	std::cout << "Last name : " << getlastname() << std::endl;
	std::cout << "Nick name : " << getnickname() << std::endl;
	std::cout << "Number : " << getnumber() << std::endl;
	std::cout << "Darkest secret : " << getsecret() << std::endl;
}

void	Contact::displayMenu()
{
	if (firstname.length() > 10)
		std::cout << firstname.substr(0, 9) << ".|";
	else
		std::cout << std::string(10 - firstname.length(), ' ') << firstname << "|";
	if (lastname.length() > 10)
		std::cout << lastname.substr(0, 9) << ".|";
	else
		std::cout << std::string(10 - lastname.length(), ' ') << lastname << "|";
	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::string(10 - nickname.length(), ' ') << nickname << std::endl;
}

Contact::Contact(std::string s[5])
{
	firstname = s[0];
	lastname =s[1];
	nickname = s[2];
	number = s[3];
	secret = s[4];
}
Contact::Contact()
{}
Contact::~Contact()
{}
