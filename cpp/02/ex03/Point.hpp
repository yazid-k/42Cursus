#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point(void);
	Point(const float xValue, const float yValue);
	Point(const Point &toCopy);
	Point	&operator = (const Point &toCopy);
	~Point(void);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

#endif
