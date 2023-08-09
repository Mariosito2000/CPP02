#include "Point.hpp"

/*---CONST/DEST---*/

Point::Point(): x(Fixed()), y(Fixed())
{
	std::cout << "Point default constructor called\n";
}

Point::~Point()
{
	std::cout << "Point destructor called\n";;
}

Point::Point(const float X, const float Y): x(Fixed(X)), y(Fixed(Y))
{
	std::cout << "Point float constructor called\n";
}

Point::Point( const Point &P): x(Fixed(P.x)), y(Fixed(P.y))
{
	std::cout << "Point copy constructor called\n";
}

/*---MEMBER FUNCTIONS---*/

const Fixed &	Point::getX() const
{
	return (this->x);
}

const Fixed &	Point::getY() const
{
	return (this->y);
}

/*---OPERATORS---*/

const Point &	Point::operator = (const Point &a)
{
	const_cast<Fixed &>(this->x)=a.getX();
	const_cast<Fixed &>(this->y)=a.getY();
	return (*this);
}
