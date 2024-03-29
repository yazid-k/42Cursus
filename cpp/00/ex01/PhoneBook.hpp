#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
	void	displayContacts();
};
#endif
