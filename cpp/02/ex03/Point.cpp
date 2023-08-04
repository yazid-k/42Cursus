#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue)
{
}

Point::Point(const Point &toCopy) : x(toCopy.x), y(toCopy.y)
{
}

Point	&Point::operator = (const Point &toCopy)
{
	(Fixed)this->x = toCopy.getX();
	(Fixed)this->y = toCopy.getY();
	return (*this);
}

Point::~Point(void)
{
}

Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}
