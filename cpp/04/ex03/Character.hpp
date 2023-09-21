#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private :
	const std::string	name;
	AMateria			*inv[4];
public :
	Character(void);
	Character(std::string name);
	Character(const Character &toCopy);
	Character	&operator = (const Character &toCopy);
	~Character(void);

	std::string	const & getName() const;
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, ICharacter& target);
};

#endif
