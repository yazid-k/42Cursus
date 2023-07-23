#include <iostream>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;
	std::cout << "String address : " <<&string << std::endl;
	std::cout << "Address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Address held by stringREF : " << &stringREF << std::endl;
	std::cout << "String value : " <<string << std::endl;
	std::cout << "String value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "String value pointed to by stringREF : " << stringREF << std::endl;
}
