#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed wOne;
	Fixed wTwo;

	wOne = ((a.getX() * (c.getY() - a.getY())) + ((point.getY() - a.getY()) * (c.getX() - a.getX()))
		- (point.getX() * (c.getY() - a.getY())))
		/ (((b.getY() - a.getY()) * (c.getX() - a.getX())) - ((b.getX() - a.getX()) * (c.getY() - a.getY())));
	
	wTwo = (point.getY() - a.getY() - (wOne * (b.getY() - a.getY())))
		/ (c.getY() - a.getY());

	if (wTwo > 0 && wOne > 0 && wTwo + wOne < 1)
		return (true);
	return (false);
}
	