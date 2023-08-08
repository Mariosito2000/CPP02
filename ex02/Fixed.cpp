#include "Fixed.hpp"

/*---CONST/DEST---*/

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	this->value = a.getRawBits();
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	this->value = i << fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	this->value = (int)roundf(f * (1 << fractionalBits));
}

/*---STATIC FUNCTIONS---*/

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const	Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*---MEMBER FUNCTIONS---*/

int		Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int const Raw)
{
	this->value = Raw;
}

float	Fixed::toFloat() const
{
	float	R;
	R = (float)this->value / (1 << fractionalBits);
	return (R);
}

int		Fixed::toInt() const
{
	return (this->value >> fractionalBits);
}

/*---OPERATORS---*/

/*---ASSIGNMENT---*/

Fixed &	Fixed::operator = (const Fixed &a)
{
	this->setRawBits(a.getRawBits());
	return (*this);
}

/*---COMPARISON---*/

bool	Fixed::operator > (const Fixed &a) const
{
	if (this->getRawBits() > a.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator < (const Fixed &a) const
{
	if (this->getRawBits() < a.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator >= (const Fixed &a) const
{
	if (this->getRawBits() >= a.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator <= (const Fixed &a) const
{
	if (this->getRawBits() <= a.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator == (const Fixed &a) const
{
	if (this->getRawBits() == a.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator != (const Fixed &a) const
{
	if (this->getRawBits() != a.getRawBits())
		return (true);
	else
		return (false);
}

/*---INCREMENT / DECREMENT---*/

Fixed &	Fixed::operator ++ ()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed old = *this;
	operator++();
	return (old);
}

Fixed &	Fixed::operator -- ()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

/*---ARITHMETIC---*/

Fixed	operator + (const Fixed &a, const Fixed &b)
{
	Fixed R;
	R.setRawBits((a.getRawBits() + b.getRawBits()));
	return (R);
}

Fixed	operator - (const Fixed &a, const Fixed &b)
{
	Fixed R;
	R.setRawBits((a.getRawBits() - b.getRawBits()));
	return (R);
}

Fixed	operator * (const Fixed &a, const Fixed &b)
{
	Fixed R;
	R.setRawBits(((long int)a.getRawBits() * (long int)b.getRawBits()) / (1 << 8));
	return (R);
}

Fixed	operator / (const Fixed &a, const Fixed &b)
{
	Fixed R;

	R.setRawBits(((long int)a.getRawBits() * (1 << 8)) / (long int)b.getRawBits());
	return (R);
}

std::ostream& operator << (std::ostream& os, const Fixed &a)
{
	std::cout << a.toFloat();
	return (os);
}