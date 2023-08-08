#include "Fixed.hpp"

/*---CONST/DEST---*/

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	this->setRawBits(a.getRawBits());
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(i << fractional_bits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	this->setRawBits((int)roundf(f * (1 << fractional_bits)));
}

/*---MEMBER FUNCTIONS---*/

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int const Raw)
{
	std::cout << "setRawBits function called\n";
	this->value = Raw;
}

float	Fixed::toFloat() const
{
	float	R;
	R = (float)this->value / (1 << fractional_bits);
	return (R);
}

int		Fixed::toInt() const
{
	return (this->value >> fractional_bits);
}

/*---OPERATORS---*/

Fixed &	Fixed::operator = (const Fixed &a)
{
	std::cout << "Asignation operator called\n";
	this->value = a.getRawBits();
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Fixed &a)
{
	std::cout << a.toFloat();
	return (os);
}