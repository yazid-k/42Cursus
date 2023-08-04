#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed denom = ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	Fixed coeffA = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denom;
	Fixed coeffB = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denom;
	Fixed coeffC = Fixed(1) - coeffA - coeffB;
	return (coeffA > 0.0f && coeffA < 1.0f && coeffB > 0.0f && coeffB < 1.0f && coeffC > 0.0f && coeffC < 1.0f);
	return (true);
}
