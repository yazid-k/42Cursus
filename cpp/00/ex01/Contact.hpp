#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	number;
	std::string	secret;
public:
	std::string	getfirstname();
	std::string	getlastname();
	std::string	getnickname();
	std::string	getnumber();
	std::string	getsecret();
	void		setfirstname(std::string fn);
	void		setlastname(std::string ln);
	void		setnickname(std::string nn);
	void		setnumber(std::string num);
	void		setsecret(std::string s);
	void		displayContact();
	void		displayMenu();
	Contact(std::string s[5]);
	Contact();
	~Contact();
};
#endif
