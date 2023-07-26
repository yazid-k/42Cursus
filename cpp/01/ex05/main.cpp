#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl	harl;
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	return 0;
}
