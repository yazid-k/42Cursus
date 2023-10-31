#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>
struct Data
{
	int	a;
	int	b;
};


class Serializer
{
private:
public:
	Serializer(void);
	Serializer(const Serializer &toCopy);
	Serializer	&operator = (const Serializer &toCopy);
	~Serializer(void);

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);
};

#endif
