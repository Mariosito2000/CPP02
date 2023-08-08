#pragma once
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:

	const Fixed	x;
	const Fixed	y;

public:

/*---CONST/DEST---*/

	Point();
	~Point();

	Point(const float, const float);
	Point( const Point &);

/*---MEMBER FUNCTIONS---*/

	const Fixed &	getX() const;
	const Fixed &	getY() const;

/*---OPERATORS---*/

	const Point &	operator = (const Point &);

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif