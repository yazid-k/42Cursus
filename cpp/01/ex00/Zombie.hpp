#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	void	announce(void);
	Zombie(/* args */);
	~Zombie();
};

#endif
